class Solution {
    void dynamicHelper(vector<int>& jobDifficulty, int daysLeft, int position, vector<vector<int>>& memo) {
        int len = jobDifficulty.size();

        if (memo[daysLeft][position] != 0) {
            return;
        }

        if (daysLeft == 1) {
            int num = 0;

            for (int i = position; i < len; i++) {
                num = max(num, jobDifficulty[i]);
            }

            memo[daysLeft][position] = num;
            return;
        }

        int maxDifficulty = jobDifficulty[position];

        daysLeft--;

        int stop = len - position - daysLeft + 1;
        int res = INT_MAX;

        for (int i = 1; i < stop; i++) {
            maxDifficulty = max(maxDifficulty, jobDifficulty[position + i - 1]);

            int other = memo[daysLeft][position + i];

            if (other == 0) {
                dynamicHelper(jobDifficulty, daysLeft, position + i, memo);
                other = memo[daysLeft][position + i];
            }

            res = min(res, other + maxDifficulty);
        }

        memo[daysLeft + 1][position] = res;
    }
public:
    // idea url
    // https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/description/comments/2187175
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int len = jobDifficulty.size();

        // we need at least one job every day
        if (len < d) {
            return -1;
        }
        
        int sum = accumulate(jobDifficulty.begin(), jobDifficulty.end(), 0);

        if (sum == 0) {
            return 0;
        }

        vector<vector<int>> memo(d + 1, vector<int>(len, 0));

        dynamicHelper(jobDifficulty, d, 0, memo);

        return memo[d][0];
    }
};