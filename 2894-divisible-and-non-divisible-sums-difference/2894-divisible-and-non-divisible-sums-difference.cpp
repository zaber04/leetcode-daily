class Solution {
    int firstApproach(int n, int m) {
        int num1 = 0, num2 = 0;

        for (int i = 1; i <= n; i++) {
            if (i % m == 0) {
                num2 += i;
            } else {
                num1 += i;
            }
        }

        return num1-num2;
    }
    
    int secondApproach(int n, int m) {
        // sum of nums upto n is sum = n*(n+1)/2
        // multiples of m present in range [1,n] is k = n/m
        int allSum = (n & 1) ? ((n+1) >> 1) * n : (n >> 1) * (n+1);
        int k = n / m;
        int divisibleSum = ((k & 1) ? ((k+1) >> 1) * k : (k >> 1) * (k+1)) * m;
        
        return allSum - (divisibleSum << 1); // multiply by 2 because we initially added the items we need to subtract in allSum --> instead of 1+2-3+4, we did 1+2+3+4
    }
public:
    int differenceOfSums(int n, int m) {
        // return firstApproach(n, m);
        return secondApproach(n, m);
    }
};