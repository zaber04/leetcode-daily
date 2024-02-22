class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int, int> hashmap;
        vector<int> indegree(n+1, 0);
        vector<int> outdegree(n+1, 0);

        if (n == 1) {
            return 1;
        }

        for (auto node : trust) {
            indegree[node[1]]++;
            outdegree[node[0]]++;
        }

        for (int i = 1; i <= n; i++) {
            if ((indegree[i] == (n-1)) && (outdegree[i] == 0)) {
                return i;
            }
        }

        return -1;
    }
};