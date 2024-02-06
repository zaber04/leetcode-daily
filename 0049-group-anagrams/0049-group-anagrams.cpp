#pragma GCC optimize("O3", "unroll-loops")

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<int>> hashmap;

        int len = strs.size();

        for (int i = 0; i < len; i++) {
            string temp = strs[i];

            sort(temp.begin(), temp.end());

            if (hashmap.count(temp) == 0) {
                hashmap[temp] = {i};
            } else {
                hashmap[temp].push_back(i);
            }
        }

        vector<vector<string>> out(hashmap.size());

        int looper = 0;

        for (auto& [key, value]: hashmap) {
            for (int index:value) {
                out[looper].push_back(strs[index]);
            }
            looper++;
        }

        return move(out);
    }
};


auto init = []() { 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();