class Solution {
    int firstAproach(string haystack, string needle) {
        int hayLen  = haystack.length();
        int needLen = needle.length();

        for (int i = 0, range = (hayLen - needLen + 1); i <= range; i++) {
            if (haystack.substr(i, needLen) == needle) {
                return i;
            }
        }

        return -1;
    }
public:
    int strStr(string haystack, string needle) {
        return firstAproach(haystack, needle);
    }
};