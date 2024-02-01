class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;

        for (string token : tokens) {
            if (token.length() > 1 || isdigit(token[0])) {
                stk.push(stoi(token));
            } else {
                int right = stk.top();
                stk.pop();

                int left = stk.top();
                stk.pop();

                switch (token[0]) {
                    case '+':
                        stk.push(left + right);
                        break;
                    case '-':
                        stk.push(left - right);
                        break;
                    case '*':
                        stk.push(left * right);
                        break;
                    default:
                        stk.push(left / right);
                        break;
                }
            }
        }

        return stk.top();
    }
};