class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int len = nums.size();
        long long ret = 0;
        vector<map<long long, int>> counter(len);

        for (int i = 1; i < len; i++) {
            for (int j = 0; j < i; j++) {
                long long diff = (long long)(nums[i]) - (long long)(nums[j]);
                int sum = 0;

                if (counter[j].find(diff) != counter[j].end()) {
                    sum = counter[j][diff];
                }

                counter[i][diff] += sum + 1;
                ret += (long long)(sum);
            }
        }

        return (int)(ret);
    }
};