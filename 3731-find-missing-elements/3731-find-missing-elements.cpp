class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_set<int> hashset(nums.begin(), nums.end());
        int minimum = ranges::min(nums);
        int maximum = ranges::max(nums);

        vector<int> result;

        for (int i = minimum + 1; i < maximum; i++) {
            if (!hashset.contains(i)) {
                result.push_back(i);
            }
        }

        return result;
    }
};