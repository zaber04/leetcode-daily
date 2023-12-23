class Solution {
    // clim(i) = climb(i-1) + climb(i-2)
    int climb(int n, vector<int> &memo) {
        if (memo[n] != 0) {
            return memo[n];
        }

        int val1 = climb(n-1, memo);
        int val2 = climb(n-2, memo);
       
        memo[n] = val1 + val2;

        return memo[n];
    }
public:
    int climbStairs(int n) {
        vector<int> memo;

        memo.push_back(0);
        memo.push_back(1);
        memo.push_back(2);
        memo.push_back(3);
        memo.push_back(5);
        memo.push_back(8);

        if (n <= 5) {
            return memo[n];
        }

        memo.resize(n+1);


        // 1 <= n <= 45

        // 1 --> 1 ---> 1
        // 2 --> 1+1/2 ---> 2
        // 3 --> 1+1+1/1+2/2+1 ---> 3
        // 4 --> 1*4/1*2+2/1+2+1/2+1*2/2+2 ---> 5
        // 5 --> 1*5/1*3+2/1*2+2+1/1+2+1*2/2+1*3/1+2*2/2+1+2/2*2+1 --> 6

        // select k 1's and m 2's such that k+2m = n, k>=0, m>=0

        return climb(n, memo);
    }
};