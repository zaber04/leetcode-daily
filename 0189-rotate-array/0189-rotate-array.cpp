class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();

        if (len == 1 || k == 0) {
            return;
        }

        if (k > len) {
            k = k % len;

            if (k == 0) {
                return;
            }
        }

        // Reverse the whole array. 
        reverse(nums.begin(), nums.end());

        // Then reverse the first k elements.
        reverse(nums.begin(), nums.begin() + k);

        // Finally reverse the remaining elements.
        reverse(nums.begin() + k, nums.end());


        // for (int i = 0; i < len - k; i++) {
        //     nums.push_back(nums[i]);
        // }

        // nums.erase(nums.begin(), nums.begin() + len - k);
    }
};