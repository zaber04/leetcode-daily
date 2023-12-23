class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        // for sorted array and sigle itemed array
        if (nums[low] <= nums[high]) {
            return nums[low];
        }

        while (low < high) {
            int mid = (high + low) >> 1;

            // if (nums[mid+1] < nums[mid]) {
            //     return nums[mid+1];
            // }

            // if (nums[mid-1] < nums[mid]) {
            //     return nums[mid];
            // }


            if (nums[high] < nums[mid]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return nums[low];
    }
};