// #pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    int scoreOfString(string s) {
        int sum = 0;
        int len = s.size();

        for (int i = 1; i < len; i++) {
            sum += abs(s[i] - s[i-1]);
        }

        return sum;
    }
};

// auto init = []() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     return 'c';
// }();