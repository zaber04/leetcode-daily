int speed = []() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result = 0;
        int len = columnTitle.length();

        for (int i = 0; i < len; i++) {
            result *= 26;
            result += (columnTitle[i] - 'A' + 1);
        }

        return result;
    }
};