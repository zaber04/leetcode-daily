class Solution {
public:
    void parentheses(int open, int closed, string &par, vector<string> &ans) {
        if (open == 0 & closed == 0) {
            ans.push_back(par);
        }

        if (open > 0) {
            par += "(";
            parentheses(open - 1, closed, par, ans);
            par.pop_back();
        }

        if (closed > 0 && closed > open) {
            par += ")";
            parentheses(open, closed - 1, par, ans);
            par.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        string par = "(";

        int open  = n-1;
        int closed = n;

        parentheses(n-1, n, par, ans);

        return ans;
    }
};