class Solution {
    int subarraySum(vector<int>& nums, int k) {
        int count = 0, sum = 0, len = nums.size();

        map<int, int> mp;

        for (int i = 0; i < len; i++) {
            sum += nums[i];

            if (sum == k) {
                count++;
            }

            if (mp.find(sum-k) != mp.end()) {
                count+=mp[sum-k];  
            }

            mp[sum]++;
        }

        return count;
    }
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int result = 0;
        int len = matrix.size();
        int row = matrix[0].size();

        for (int i = 0; i < len; i++) {
            vector<int> sum(row, 0);

            for (int j = i; j < len; j++) {
                for(int k = 0; k < row; k++) {
                    sum[k] += matrix[j][k];
                }

                result += subarraySum(sum, target);
            }
        }

        return result;
    }
};