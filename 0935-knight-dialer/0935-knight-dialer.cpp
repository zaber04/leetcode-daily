class Solution {
    int dynamicApproach(int n, vector<int> memo) {
        // dp[i][i] --> [(i+2, j+1), (i+2, j-1), (i-2, j+1), (i-2, j-1),
        //               (i+1, j+2), (i+1, j-2), (i-1, j+2), (i-1, j-2)]

        return 0;
    }
public:
    int knightDialer(int n) {
        if (n == 1) {
            return 10;
        }

        const int bymod = 1000000007;
        
        int grid[4][3] = {{1,2,3}, {4,5,6}, {7,8,9}, {-1, 0, -1}};

        unordered_map<int, vector<int>> validMovs;
        validMovs[0] = {4, 6}; // from 0
        validMovs[1] = {6, 8}; // from 1
        validMovs[2] = {7, 9}; // from 2
        validMovs[3] = {4, 8}; // from 3
        validMovs[4] = {0, 3, 9}; // from 4
        validMovs[5] = {}; // from 5
        validMovs[6] = {0, 1, 7}; // from 6
        validMovs[7] = {2, 6}; // from 7
        validMovs[8] = {1, 3}; // from 8
        validMovs[9] = {2, 4}; // from 9


        // dp base
        vector<int> start(10, 1); // base case --> n = 1

        for (int i = 2; i <= n; i++) {
            vector<int> temp(10, 0);

            for (auto [key, val]: validMovs) {
                for (auto j: val) {
                    temp[key] = (temp[key] + start[j]) % bymod;
                }
            }

            // update state to last state
            start = temp;
        }

        int ret = 0;

        for (auto i: start) {
            ret = (ret + i) % bymod;
        }

        return ret;
    }
};