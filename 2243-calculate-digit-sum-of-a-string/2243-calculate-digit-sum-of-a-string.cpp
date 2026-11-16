class Solution {
public:
    string digitSum(string s, int k) {
        while (s.size() > k) {
            string temp;
            int len = s.size();

            for (int i = 0; i < len; i += k) {
                int val = 0;

                for (int j = i; j < min(i + k, len); ++j) {
                    val += s[j] - '0';
                }

                temp.append(to_string(val));
            }

            s = temp;
        }

        return s;
    }
};