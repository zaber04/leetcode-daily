void reColor(vector<vector<int>>& image, int x, int y, int target, int color, int xMax, int yMax) {
    if (x < 0 || y < 0 || x == xMax || y == yMax || image[x][y] == color || image[x][y] != target) {
        return;
    }

    image[x][y] = color;
    // (x, y) => {(x+1, y), (x-1, y), (x, y+1), (x, y-1)}
    reColor(image, x+1, y, target, color, xMax, yMax);
    reColor(image, x-1, y, target, color, xMax, yMax);
    reColor(image, x, y+1, target, color, xMax, yMax);
    reColor(image, x, y-1, target, color, xMax, yMax);
}

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // (x, y) => {(x+1, y), (x-1, y), (x, y+1), (x, y-1)}
        // we can consider these too be 4 children of current node. we do dfs
        int xMax = image.size(), yMax = image[0].size();
        reColor(image, sr, sc, image[sr][sc], color, xMax, yMax);

        return image;
    }
};