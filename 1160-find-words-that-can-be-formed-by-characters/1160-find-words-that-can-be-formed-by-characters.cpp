class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int len = words.size();
        int nel = chars.size();

        unordered_map<char, int> source;

        for (auto c:chars) {
            source[c]++;
        }

        int ret = 0;
        for (auto str:words) {
            unordered_map<char, int> temp;

            for (auto c:str) {
                temp[c]++;
            }

            bool flag = true;
            for (auto it:temp) {
                if (it.second > source[it.first]) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                ret += str.size();
            }
        }

        return ret;
    }
};