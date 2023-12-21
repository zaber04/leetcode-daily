class Solution {
public:
    int countHomogenous(string s) {
        const int mod = 1000000007;
        // homogenous string "aaaaaaa" of length N contains N * (N + 1) / 2 homogenous substrings
        long long sum = 0LL;

        // find continuous same character
        int tempLen = 1;

        for (int i = 0, len = s.size(); i < len-1; i++) {
            if (s[i] == s[i+1]) {
                tempLen++;
            } else {
                sum += (1LL * tempLen * (tempLen + 1)) / 2;

                tempLen = 1;
            }
        }

        // gotta do it for last character as well.
        sum += (1LL * tempLen * (tempLen + 1)) / 2;


        return sum % mod;
    }
};