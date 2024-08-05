class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> hashmap;

        for (string &str: arr) {
            hashmap[str]++;
        }

        for  (string &str: arr) {
            if (hashmap[str] == 1) {
                k--;
            }

            if (k == 0) {
                return str;
            }
        }

        return "";
    }
};