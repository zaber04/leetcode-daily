class Solution {
    int firstAproach(vector<int>& nums, int val) {
        int counter = 0;
        int len = nums.size();

        while (counter < len) {
            if (nums[counter] == val) {
                nums[counter] = nums[len-1];

                // our end of array is now at len - 1 instead
                len--;
            } else {
                counter++;
            }
        }

        return counter;
    }

    int secondAproach(vector<int>& nums, int val) {
        int counter = 0;
        int len = nums.size();

        for (int i = 0; i < len; i++) {
            if (nums[i] != val) {
                nums[counter] = nums[i];
                counter++;
            }
        }

        return counter;
    }
public:
    int removeElement(vector<int>& nums, int val) {
        return firstAproach(nums, val);
        // return secondAproach(nums, val);
    }
};