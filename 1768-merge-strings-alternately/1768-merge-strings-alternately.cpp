class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        
        string s = "";
        int smaller, larger;
        string word;
        if (len1 < len2) {
            smaller = len1;
            larger = len2;
            word = word2;
        } else {
            smaller = len2;
            larger = len1;
            word = word1;
        }
        
        for (int i=0; i<smaller;i++) {            
            s += word1[i];
            s += word2[i];
        }
        
        for (int i=smaller; i<larger;i++) {
            s += word[i];
        }
        
        return s;
        
    }
};