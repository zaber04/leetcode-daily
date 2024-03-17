int speed = []() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> result;

        for (char col = s[0]; col <= s[3]; col++) {
            for (char row = s[1]; row <= s[4]; row++) {
                result.push_back({ col, row });
            }
        }

        return result;
    }
};