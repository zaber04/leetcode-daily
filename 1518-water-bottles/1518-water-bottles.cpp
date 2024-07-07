class Solution {
    int firstApproach(int numBottles, int numExchange) {
        int total = 0;
        
        while (numBottles >= numExchange) {
            total += numExchange;
            numBottles -= numExchange;
            numBottles++;
        }

        return total + numBottles;
    }

    int secondApproach(int numBottles, int numExchange) {
        int total = 0;
        
        while (numBottles >= numExchange) {
            int K = numBottles / numExchange;
            total += numExchange * K;
            numBottles -= numExchange * K;

            numBottles += K;
        }

        return total + numBottles;
    }
public:
    int numWaterBottles(int numBottles, int numExchange) {
        // return firstApproach(numBottles, numExchange);
        return secondApproach(numBottles, numExchange);
    }
};

// auto init = []() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     return 'c';
// }();