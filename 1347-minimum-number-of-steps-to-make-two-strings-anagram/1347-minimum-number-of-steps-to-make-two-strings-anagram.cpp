class Solution {
public:
    int minSteps(string s, string t) {
        int freq[26] = {0};
        int sLen = s.length();

        for (int i = 0; i < sLen; i++) {
            freq[t[i] - 'a']++;
            freq[s[i] - 'a']--;
        }

        int ret = 0;

        for (int i =  0; i < 26; i++) {
            ret += max(0, freq[i]);
        }

        return ret;
    }
};