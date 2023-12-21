#define BYMOD 1000000007
class Solution {
    int rev(int n) {
        // 1234
        // 0*10 + 4 = 4
        // 10*4 + 3 = 43
        // 10*43+ 2 = 432
        // 10*432+1 = 4321
        int r = 0;
        while (n > 0) {
            r = 10 * r + (n % 10);
            n /= 10;
        }
        return r;
    }

    // nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
    // nums[i] - rev(nums[i]) == nums[j] - rev(nums[j])
    bool isNice(int i, int j, int len) {
        return false;
    }
public:
    int countNicePairs(vector<int>& nums) {
        int len = nums.size();

        for (int i = 0; i < len; i++) {
            nums[i] -= rev(nums[i]);
            
        }

        long count = 0;
        unordered_map<int, int> map;

        for (int i = 0; i < len; i++) {
            count = (count + map[nums[i]]) % BYMOD;
            map[nums[i]]++;
        }

        return count % BYMOD;
    }
};