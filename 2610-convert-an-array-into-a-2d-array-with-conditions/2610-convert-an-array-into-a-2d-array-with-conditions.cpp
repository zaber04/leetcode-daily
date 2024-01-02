class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int len = nums.size();
        vector<int> freq(len + 1);

        vector<vector<int>> ret;

        for (int num: nums) {
            if (freq[num] >= ret.size()) {
                ret.push_back({});
            }

            ret[freq[num]].push_back(num);
            freq[num]++;
        }

        return ret;
    }
};