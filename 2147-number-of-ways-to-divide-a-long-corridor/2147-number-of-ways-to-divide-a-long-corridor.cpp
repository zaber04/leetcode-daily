class Solution {
public:
    int numberOfWays(string corridor) {
        const int bymod = 1000000007;
        unsigned long long int ret = 1LLU;
        int seats = 0;
        int len = corridor.length();

        vector<int> sIndex;
        int loc = 0;

        for (int i = 0; i < len; i++) {
            if (corridor[i] == 'S') {
                seats++;
                sIndex.push_back(i);
            }
        }

        // if seat_count <  2 --> 0
        // odd seats --> 0
        if (seats < 2 || seats % 2) {
            return 0;
        }

        // if seat_count == 2 --> 1
        if (seats == 1) {
            return 1;
        }

        // if seat_count >=  4 --> ?
        // k plants in between --> k + 1 choices
        // 4 or more seats -> seat 2 and 3 at i and j --> plant count --> (j-1-1) --> choice count --> (j-i)
        // seat 0 -->1, seat 2 --> 3, seat 4 --> 5

        // take product of non-paired neighbours
        int prevLast  = 1; // 0 --> 1
        int currFirst = 2; // 2 --> 3

        while (currFirst < seats) {
            // 4 or more seats -> seat are at i and j --> plant count --> (j-1-1) --> choice count --> (j-i)
            ret *= (sIndex[currFirst] - sIndex[prevLast]);
            ret %= bymod;

            prevLast  += 2;
            currFirst += 2;
        }



        return (int)(ret % bymod);
    }
};