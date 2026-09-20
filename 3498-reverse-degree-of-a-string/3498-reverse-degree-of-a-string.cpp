class Solution {
public:
    int reverseDegree(string s) {
        int result = 0;
        int len = s.size();

        for (int i = 1; i <= len; i++) {
            result += (26 - (s[i-1] - 'a')) * i;
        }

        return result;
    }
};