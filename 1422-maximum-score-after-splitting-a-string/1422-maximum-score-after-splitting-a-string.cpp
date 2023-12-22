class Solution {
public:
    int maxScore(string s) {
        int oneCount = 0;
        int zeroCount = 0;
        int highest = INT_MIN;
        int len = s.length();

        for (int i = 0; i < len - 1; i++) {
            if (s[i] == '1') {
                oneCount++;
            } else {
                zeroCount++;
            }

            highest = max(highest, zeroCount - oneCount);
        }

        if (s[len - 1] == '1') {
            oneCount++;
        }

        return highest + oneCount;
    }
};