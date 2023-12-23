class Solution {
public:
    bool isAnagram(string s, string t) {
        int sLen = s.length();
        int tLen = t.length();

        if (sLen != tLen) {
            return false;
        }

        int arr[26] = {0};

        for (int i = 0; i < sLen; i++) {
            ++arr[s[i] - 'a'];
            --arr[t[i] - 'a'];
        }

        for (int count : arr) {
            if (count != 0) {
                return false;
            }
        }
        return true;
    }
};