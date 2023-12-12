class Solution {
    // find largest two elements
    int firstApproach(vector<int>& nums) {
        int len = nums.size();

        if (len == 2) {
            return (nums[0]-1)*(nums[1]-1);
        }

        int small = min(nums[0], nums[1]);
        int large = max(nums[0], nums[1]);

        for (int i = 2; i < len; i++) {
            if (nums[i] > large) {
                // old value of large > small?
                small = large;
                large = nums[i];
            } else if (nums[i] > small) {
                small = nums[i];
            }
        }

        return (large - 1) * (small - 1);
    }
public:
    int maxProduct(vector<int>& nums) {
        return firstApproach(nums);
    }
};