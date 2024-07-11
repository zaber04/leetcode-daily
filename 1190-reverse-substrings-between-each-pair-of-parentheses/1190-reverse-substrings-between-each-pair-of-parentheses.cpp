class Solution {
public:
    string reverseParentheses(string s) {
        int len = s.length();

        if (len <= 1) {
            return s;
        }

        stack<int> openPositions;
        vector<int> pair(len);

        // find corresponding start and end for each bracket
        for (int i = 0; i < len; i++) {
            if (s[i] == '(') {
                openPositions.push(i);
            }

            if (s[i] == ')') {
                int j = openPositions.top();
                openPositions.pop();

                pair[i] = j;
                pair[j] = i;
            }
        }

        string result;

        for (int idx = 0, direction = 1; idx < len; idx += direction) {
            if (s[idx] == '(' || s[idx] == ')') {
                idx = pair[idx];
                direction = -direction;
            } else {
                result += s[idx];
            }
        }

        return result;
    }
};