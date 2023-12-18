class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int large1 = 0, large2 = 0;
        int small1 = INT_MAX, small2 = INT_MAX;

        for (int num: nums) {
            if (num > large1) {
                large2 = large1;
                large1 = num;
            } else {
                large2 = max(large2, num);
            }

            if (num < small1) {
                small2 = small1;
                small1 = num;
            } else {
                small2 = min(small2, num);
            }
        }

        return large1 * large2 - small1 * small2;
    }
};