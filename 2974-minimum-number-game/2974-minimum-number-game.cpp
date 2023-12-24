class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int len = nums.size();
        
        vector<int> arr;
        
        while (len > 1) {
            arr.push_back(nums[len-2]);
            arr.push_back(nums[len-1]);
            len -= 2;
        }
        
        return arr;
    }
};