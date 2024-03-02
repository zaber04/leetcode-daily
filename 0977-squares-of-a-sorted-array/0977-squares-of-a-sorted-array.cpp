#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int len = nums.size();

        int left = 0, right = len - 1;

        vector<int> result(len);

        for (int i = right; i >= 0; i--) {
            int temp;

            if (abs(nums[left]) > abs(nums[right])) {
                temp = nums[left];
                left++;
            } else {
                temp = nums[right];
                right--;
            }

            result[i] = temp * temp;
        }

        return result;
    }
};
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();