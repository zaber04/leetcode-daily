class Solution {
public:
    int countSeniors(vector<string>& details) {
        int len = details.size();
        int result = 0;

        for (int i = 0; i < len; i++) {
            int age = stoi(details[i].substr(11, 2));

            if (age > 60) {
                result++;
            }
        }

        return result;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();