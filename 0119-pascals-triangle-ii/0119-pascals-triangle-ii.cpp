class Solution {
    // combinatorics
    vector<int> firstApproach(int n) {
        if (n == 0) {
            return {1};
        }

        if (n == 1) {
            return {1, 1};
        }

        vector<int> out(n + 1);

        // nC0 = 1
        // nC1 = n
        // nC2 = n(n-1)/(1*2)
        // nc3 = n(n-1)(n-2)/(1*2*3) = nC2 * (n - 3 + 1) / 3
        // nCr = nCr-1 * (n - r + 1) / r

        unsigned long long int last  = 1LLU;

        out[0] = last;
        out[n] = last;

        // pattern repeats after half
        for (int r = 1, n2 = (n >> 1); r <= n2; r++) {
            last = last * (n - r + 1) / r;
            out[r] = (int)(last);
            out[n-r] = (int)(last);
        }

        return out;
    }
public:
    vector<int> getRow(int rowIndex) {
        return firstApproach(rowIndex);
    }
};