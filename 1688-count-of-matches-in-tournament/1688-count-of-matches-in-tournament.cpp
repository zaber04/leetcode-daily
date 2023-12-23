class Solution {
    // just add ceiling of (n/2) every time
    int firstApproach(int n) {
        // n % 2 == 0 --> n/2 matches 
        // n % 2 == 1 --> 1 auto pass,  (n-1)/2 matches
        if (n == 1) {
            return 0;
        }

        int matches = 0;
        while (n > 1) {
            matches += (n & 1) ? ((n+1) >> 1) : (n >> 1);
            n >>= 1;
        }

        return matches;
    }

    // for n = 32, if we print the matches
    // 1 + 2 + 4 + 8 + 16 = 32 - 1
    int secondApproach(int n) {
        return n - 1;
    }
public:
    int numberOfMatches(int n) {
        // return firstApproach(n);
        return secondApproach(n);
    }
};