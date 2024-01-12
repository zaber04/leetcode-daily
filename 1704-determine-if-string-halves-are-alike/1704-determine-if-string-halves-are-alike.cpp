class Solution {
    int vowelCount(string str) {
        string vowels = "aeiouAEIOU";
        int ret = 0;

        for (char ch : str) {
            if (vowels.find(ch) != string::npos) {
                ret++;
            }
        }

        return ret;
    }
public:
    bool halvesAreAlike(string s) {
        int len = s.size();
        string a = s.substr(0, len / 2); // bottom half
        string b = s.substr(len / 2); // upper half

        int vowelA = vowelCount(a);
        int vowelB = vowelCount(b);

        return vowelA == vowelB;
    }
};