class Solution {
public:
    int xorOperation(int n, int start) {
        int res = start;

        for (int i = start + 2, j = 2; j <= n; i += 2, j++) {
            res ^= i;
        }

        return res;
    }
};