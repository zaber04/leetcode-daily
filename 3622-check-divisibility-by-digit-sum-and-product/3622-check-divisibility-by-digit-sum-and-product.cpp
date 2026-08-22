class Solution {
public:
    bool checkDivisibility(int n) {
        int digitSum = 0;
        int digitProduct = 1;
        int input = n;

        while (n) {
            int remainder = n % 10;
            n /= 10;

            digitSum += remainder;
            digitProduct *= remainder;
        }

        return input % (digitSum + digitProduct) == 0;
    }
};