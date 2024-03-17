int speed = []() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";

        while (columnNumber) {
            char ch = 'A' + (columnNumber - 1) % 26;
            result = ch + result;
            columnNumber = (columnNumber - 1) / 26;
        }

        return result;
    }
};