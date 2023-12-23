class Solution {
    int nC2(int n) {
        return n*(n-1) >> 1;
    }

    int firstApproach(vector<int>& nums) {
        unordered_map <int, int> freq;
        int len = nums.size();

        for (int i=0; i<len; i++) {
            freq[nums[i]]++;
        }

        int res = 0;
        for (auto j: freq) {
            if (j.second > 1) {
                res += nC2(j.second);
            }
        }

        return res;
    }
public:
    int numIdenticalPairs(vector<int>& nums) {
        return firstApproach(nums);
    }
};