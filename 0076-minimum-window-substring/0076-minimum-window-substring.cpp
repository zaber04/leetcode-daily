class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> map(128, 0);

        for (char ch : t) {
            map[ch]++;
        }

        int tLen = t.size(), begin = 0, end = 0, d = INT_MAX, head = 0,
            sLen = s.size();

        while (end < sLen) {
            if (map[s[end++]]-- > 0) {
                tLen--; // in t
            }

            while (tLen == 0) { // valid
                if (end - begin < d) {
                    d = end - (head = begin);
                }

                if (map[s[begin++]]++ == 0) {
                    tLen++; // make it invalid
                }
            }
        }

        return d == INT_MAX ? "" : s.substr(head, d);
    }
};