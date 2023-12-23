#define MAX_NUM 37

class Solution {
    vector<int> memo;

    int calcTrib(int n) {
        if (memo[n] != -1) {
            return memo[n];
        }

        int t3 = calcTrib(n-3);
        int t2 = calcTrib(n-2);
        int t1 = calcTrib(n-1);

        memo[n] = t3 + t2 + t1;

        return memo[n];
    }
public:
    Solution() {
        memo.push_back(0); // 0
        memo.push_back(1); // 1
        memo.push_back(1); // 2
        memo.push_back(2); // 3
        memo.push_back(4); // 4
        memo.push_back(7); // 5

        memo.resize(MAX_NUM + 1, -1);
    }

    int tribonacci(int n) {
        if (n <= 5) {
            return memo[n];
        }
        
        return calcTrib(n);
    }
};