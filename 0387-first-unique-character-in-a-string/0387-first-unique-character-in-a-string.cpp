class Solution {
public:
    int firstUniqChar(string s) {
        int map[26] = {0};
        int len = s.length();
        int firs = 0;

        for (int i = 1; i <= len; i++) {
            char ch = s[i-1] - 'a';
            
            if (map[ch] == 0) {
                map[ch] = -i;
            } else {
                map[ch] = i;
            }
        }

        int minPos = INT_MAX;

        for (int i = 0; i < 26; i++) {
            if (map[i] < 0) {
                minPos = min(minPos, -map[i]);
            }
        }

        return minPos == INT_MAX ? -1 : minPos - 1;
    }
};