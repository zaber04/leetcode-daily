class Solution {
    int calcTrib(int n, vector<int> &memo) {
        if (memo[n] != -1) {
            return memo[n];
        }

        int t2 = calcTrib(n-2, memo);
        int t1 = calcTrib(n-1, memo);

        memo[n] = t2 + t1;

        return memo[n];
    }
public:
    int fib(int n) {
        vector<int> memo;

        memo.push_back(0); // 0
        memo.push_back(1); // 1
        memo.push_back(1); // 2
        memo.push_back(2); // 3
        memo.push_back(3); // 4
        memo.push_back(5); // 5

        if (n <= 5) {
            return memo[n];
        }

        memo.resize(n+1, -1);
        
        return calcTrib(n, memo);
    }
};