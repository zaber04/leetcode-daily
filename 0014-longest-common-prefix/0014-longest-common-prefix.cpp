class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = strs[0];
        int n = strs.size();
        int len = result.length();
     
        for (int i = 1; i < n; i++) {
            while (strs[i].find(result) != 0) {
                result = result.substr(0, len - 1);
                len--;
                if (result.empty()) {
                    return result;
                }
            }
        }

        return result;
    }
};