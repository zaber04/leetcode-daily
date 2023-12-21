class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end());

        int ret = 0;

        for (int i = 0, len = points.size(); i < len - 1; i++) {
            ret = max(ret, points[i+1][0] - points[i][0]);
        }

        return ret;
    }
};