static const int FAST__ = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int rowLen = grid.size();
        int colLen = grid[0].size();

        vector<int> rowSums(rowLen, 0);
        vector<int> colSums(colLen, 0);

        for (int row = 0; row < rowLen; row++) {
            for (int col = 0; col < colLen; col++) {
                rowSums[row] += grid[row][col];
                colSums[col] += grid[row][col];
            }
        }

        vector<vector<int>> diff(rowLen, vector<int>(colLen, 0));
        for (int row = 0; row < rowLen; row++) {
            for (int col = 0; col < colLen; col++) {
                diff[row][col] = 2 * rowSums[row] + 2 * colSums[col] - rowLen - colLen;
            }
        }

        return diff;
    }
};