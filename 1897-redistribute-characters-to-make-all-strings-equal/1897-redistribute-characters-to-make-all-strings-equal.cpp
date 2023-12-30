class Solution {
    bool firstApproach(vector<string>& words) {
        int len = words.size();

        if (len == 1) {
            return true;
        }

        vector<int> map(26, 0);

        for (string word: words) {
            for (char ch: word) {
                map[ch - 'a']++;
            }
        }

        for (int i = 0; i < 26; i++) {
            if (map[i] % len != 0) {
                return false;
            }
        }

        return true;
    }
public:
    bool makeEqual(vector<string>& words) {
        return firstApproach(words);
    }
};