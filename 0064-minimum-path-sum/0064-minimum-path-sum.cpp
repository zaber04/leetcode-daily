class Solution {
    // (x,y) ==> (x, y+1) or (x+1, y)
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        for (int i = rows - 1; i >= 0; i--) {
            for (int j = cols - 1; j >= 0; j--) {
                if (i == rows - 1 && j != cols - 1) {
                    grid[i][j] = grid[i][j] + grid[i][j+1];
                } else if (i != rows - 1 && j == cols - 1) {
                    grid[i][j] = grid[i][j] + grid[i+1][j];
                } else if (i != rows - 1 && j != cols - 1) {
                    grid[i][j] = grid[i][j] + min(grid[i+1][j], grid[i][j+1]);
                }
            }
        }

        return grid[0][0];
    }
};