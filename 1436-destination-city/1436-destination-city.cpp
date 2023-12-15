class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        int len = paths.size();

        if (len == 1) {
            return paths[0][1];
        }

        unordered_set<string> hash_set;

        for (int i = 0; i < len; i++) {
            hash_set.insert(paths[i][0]);
        }

        for (int i = 0; i < len; i++) {
            string candidate = paths[i][1];

            if (hash_set.find(candidate) == hash_set.end()) {
                return candidate;
            }
        }
        
        return "";
    }
};