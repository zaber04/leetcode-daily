class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        string out = "";
        
        for (int i = 0, limit = max(len1, len2); i < limit; i++) {
            if (i < len1) {
                out.push_back(word1[i]);
            }

            if (i < len2) {
                out.push_back(word2[i]);
            }
        }
        
        return out;
        
    }
};