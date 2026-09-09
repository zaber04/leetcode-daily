class Solution {
public:
    long long countCommas(long long n) {
        long long i = 1000;
        long long result = 0;

        while (i <= n) {
            result += (n - i + 1);
            i *= 1000;
        }

        return result;
    }
};