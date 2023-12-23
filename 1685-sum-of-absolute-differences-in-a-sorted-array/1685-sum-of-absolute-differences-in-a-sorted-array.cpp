#pragma GCC optimize("O3")
class Solution {
    vector<int> firstApproach(vector<int>& nums) {
        // For nums[i], the answer is (nums[i] - nums[0]) + (nums[i] - nums[1]) + ... + (nums[i] - nums[i-1]) + (nums[i+1] - nums[i]) + (nums[i+2] - nums[i]) + ... + (nums[n-1] - nums[i]).

        // It can be simplified to 
        // (nums[i] * i - (nums[0] + nums[1] + ... + nums[i-1])) + 
        // ((nums[i+1] + nums[i+2] + ... + nums[n-1]) - nums[i] * (n-i-1)). 
        // One can build prefix and suffix sums to compute this quickly.

        int len = nums.size();

        // by adding an extra space, we are able to remove IF condition inside loop
        vector<int> out(len, 0);
        nums.push_back(0);
        // minus part is leftSum, plus part is rightSum
        int leftSum = 0, rightSum = 0;
        
        for (int i = 1; i <= len; i++) {
            rightSum += nums[i];
        }

        #pragma unroll
        for (int i = 0; i < len; i++) {
            out[i] = ((i << 1) - len + 1) * nums[i] + rightSum - leftSum;
            leftSum += nums[i];
            rightSum -= nums[i+1]; // we increased array length to avoid overflow
        }
        return out;
    }
    
    vector<int> secondApproach(vector<int>& nums) {
        int len = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;
        vector<int> ans;
        
        for (int i = 0; i < len; i++) {
            int rightSum = totalSum - leftSum - nums[i];

            int leftCount = i;
            int rightCount = len - 1 - i;
            
            int leftTotal  = leftCount * nums[i] - leftSum;
            int rightTotal = rightSum - rightCount * nums[i];
            
            ans.push_back(leftTotal + rightTotal);
            leftSum += nums[i];
        }
        
        return ans;
    }
    
    vector<int> thirdApproach(vector<int>& nums) {
        // https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/discuss/4329011/Concise-100-approach-and-Mathematical-proof
        
        int len = nums.size();
        vector<int> ans(len, 0);
        
        for(int i = 1; i < len; i++) {
            ans[0] += nums[i] - nums[0];
        }
        
        for (int i = 1; i < len; ++i) {
            ans[i] = ans[i-1] + (2*i - len) * (nums[i] - nums[i-1]);
        }
        
        return ans;
    }
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        // return firstApproach(nums);
        // return secondApproach(nums);
        return thirdApproach(nums);
    }
};

auto init = []()
{ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();