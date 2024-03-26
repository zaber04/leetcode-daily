class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        vector<bool> seen(len + 1, false);

        for (int num : nums) {
            if (num > 0 && num <= len) {
                seen[num] = true;
            }
        }

        for (int i = 1; i <= len; i++) {
            if (!seen[i]) {
                return i;
            }
        }

        return len + 1;
    }
};