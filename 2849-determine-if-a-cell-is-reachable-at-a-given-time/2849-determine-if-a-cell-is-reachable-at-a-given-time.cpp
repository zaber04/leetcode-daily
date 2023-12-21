class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int row = abs(fx-sx);
        int col = abs(fy-sy);
        int chebyshevDistance = max(row, col);

        if (row == 0 && col == 0 && t == 1) {
            return false;
        }

        return (t >= chebyshevDistance);
    }
};