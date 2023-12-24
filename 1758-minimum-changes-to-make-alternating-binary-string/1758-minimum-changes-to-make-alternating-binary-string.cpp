class Solution {
    // we check for 1
    int firstApproach(string str) {
        int changeCount = 0;
        int len = str.length();

        for (int i = 0; i < len; i++) {
            if (i % 2) {
                if (str[i] == '0') {
                    changeCount++;
                }
            } else {
                if (str[i] == '1') {
                    changeCount++;
                }
            }
        }

        return min(changeCount, len - changeCount);
    }
public:
    int minOperations(string str) {
        return firstApproach(str);
    }
};