class Solution {
public:
    int reverse(int num) {
        int ans = 0;
        
        while (num) {
            // guaranteed overflow
            if (ans > (INT_MAX / 10) || ans < (INT_MIN / 10)) {
                return 0;
            }

            int rem = num % 10;

            // if ans == INT_MAX / 10 or ans = INT_MIN / 10
            if ((ans == INT_MAX / 10 && rem > 7) || (ans == INT_MIN / 10 && rem < -8)) {
                return 0;
            }

            ans = ans * 10 + rem;
            num /= 10;
        }

        return ans;
    }
};