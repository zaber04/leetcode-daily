class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len2 = nums.size() >> 1;
        unordered_map<int, int> hashmap;

        for (int num : nums) {
            hashmap[num]++;

            if (hashmap[num] > len2) {
                return num;
            }
        }

        return 0;
    }
};