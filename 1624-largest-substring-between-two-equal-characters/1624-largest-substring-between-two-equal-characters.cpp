class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char, int> map; // we store first position of character
        int ret = -1;
        int len = s.length();
        
        for (int  i = 0; i < len; i++) {
            if (map.find(s[i]) != map.end()) {
                ret = max(ret, i - map[s[i]] - 1);
            } else {
                map[s[i]] = i;
            }
        }
        
        return ret;
    }
};