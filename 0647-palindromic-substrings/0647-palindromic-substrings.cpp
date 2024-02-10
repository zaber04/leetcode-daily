class Solution {
public:
    int countSubstrings(string s) {
        int len = s.length();
        int out = 0;

        if (len == 0) {
            return 0;
        }

        vector<vector<bool>> memo(len, vector<bool>(len, false));

        // single leter substrings
        for (int i = 0; i < len; i++, out++) {
            memo[i][i] = true;
        }

        // double letter substrings 
        for (int i = 0; i < len - 1; i++) {
            memo[i][i+1] = (s[i] == s[i+1]);
            out += memo[i][i+1];
        }

        // substrings of length 3 to len 
        for (int siz = 3; siz <= len; siz++) {
            for (int i = 0, j = i + siz - 1; j < len; i++, j++) {
                memo[i][j] = memo[i+1][j-1] && (s[i] == s[j]);
                out += memo[i][j];
            }
        }

        return out;
    }
};