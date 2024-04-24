class Solution {
public:
    int tribonacci(int n) {
        int a = 0, b = 1, c = 1, t = 0;

        if (n == 0) {
            return 0;
        } else if (n < 3) {
            return 1;
        }

        for (int i = 3; i <= n; i++) {
            t = a + b + c;
            a = b;
            b = c;
            c = t;
        }

        return t;
    }
};