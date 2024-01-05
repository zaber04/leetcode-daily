class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        vector<int> seq(len, 0);

        int capacity = 0;

        for (int num : nums) {
            int start = 0, end = capacity;

            while (start != end) {
                int mid = start + (end - start) / 2;

                if (seq[mid] < num) {
                    start = mid + 1;
                } else {
                    end = mid;
                }
            }

            seq[start] = num;

            if (start == capacity) {
                capacity++;
            }
        }

        return capacity;
    }
};