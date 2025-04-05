class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int len = nums.size();

        if (!len) {
            return 0;
        }

        int result = 0;

        for (int num : nums) {
            result |= num;
        }

        return (result << (len - 1));
    }
};