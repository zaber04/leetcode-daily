class Solution {
public:
    int maxDepth(string str) {
        int ret = 0;

        stack<char> stk;

        for (char ch : str) {
            if (ch == '(') {
                stk.push(ch);
            } else if (ch == ')') {
                stk.pop();
            }

            ret = max(ret, (int)stk.size());
        }

        return ret;
    }
};