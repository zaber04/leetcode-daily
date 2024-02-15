class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        ios::sync_with_stdio(false);
        int len = nums.size();
        long long sum = 0;
        long long out = -1;

        sort(nums.begin(), nums.end());
        
        for (int num : nums) {
            if (num < sum) {
                out = num + sum;
            }
            sum += num;
        }

        return out;
    }
};