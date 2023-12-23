class Solution {
    bool firstApproach(vector<string>& word1, vector<string>& word2) {
        string w1 = "", w2 = "";

        for (int i = 0, len = word1.size(); i < len; i++) {
            w1 += word1[i];
        }

        for (int i = 0, len = word2.size(); i < len; i++) {
            w2 += word2[i];
        }

        return w1 == w2;
    }

    bool secondApproach(vector<string>& word1, vector<string>& word2) {
        int len1 = word1.size();
        int len2 = word2.size();

        int w1rp = 0;
        int w1cp = 0;

        int w2rp = 0;
        int w2cp = 0;

        while (w1rp < len1 && w2rp < len2) {
            if (word1[w1rp][w1cp++] != word2[w2rp][w2cp++]) {
                return false;
            }

            if (w1cp == word1[w1rp].size()) {
                w1rp++;
                w1cp = 0;
            }

            if (w2cp == word2[w2rp].size()) {
                w2rp++;
                w2cp = 0;
            }
        }

        return w1rp == len1 && w2rp == len2;
    }
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        // return firstApproach(word1, word2);
        return secondApproach(word1, word2);
    }
};