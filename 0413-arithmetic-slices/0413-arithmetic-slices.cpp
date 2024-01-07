class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int count = 0, sum = 0, len = nums.size();

        for (int i = 2; i < len; i++) {
            if (nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) {
                count++;
            } else {
                sum += (count + 1) * count / 2;
                count = 0;
            }
        }

        return sum += count * (count + 1) / 2;
    }
};