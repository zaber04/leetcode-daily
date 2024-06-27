class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int firstStart  = edges[0][0];
        int firstEnd    = edges[0][1];
        int secondStart = edges[1][0];
        int secondEnd   = edges[1][1];

        return (firstStart == secondStart || firstStart == secondEnd) ? firstStart : firstEnd;
    }
};