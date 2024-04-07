class Solution {
public:
    bool checkValidString(string str) {
        stack<int> openIndexes;
        stack<int> asteriskIndexes;

        int len = str.size();

        for (int i = 0; i < len; i++) {
            char ch = str[i];

            if (ch == '(') {
                openIndexes.push(i);
            } else if (ch == '*') {
                asteriskIndexes.push(i);
            } else {
                if (!openIndexes.empty()) {
                    openIndexes.pop();
                } else if (!asteriskIndexes.empty()) {
                    asteriskIndexes.pop();
                } else {
                    return false;
                }
            }
        }

        while (!openIndexes.empty() && !asteriskIndexes.empty()) {
            if (openIndexes.top() > asteriskIndexes.top()) {
                return false; // '*' before '(' which cannot be balanced.
            }

            openIndexes.pop();
            asteriskIndexes.pop();
        }

        return openIndexes.empty();
    }
};