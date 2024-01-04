class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> map;

        for (int num : nums) {
            map[num]++;
        }

        int ret = 0;

        for (auto [first, second]: map) {
            if (second == 1) {
                return -1;
            }

            ret += ceil(second * 1.00 / 3);
        }

        return ret;
    }
};