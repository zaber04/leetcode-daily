class Solution {
    int firstApproach(int left, int right) {
        int shift = 0;

        while (left < right) {
            left >>= 1;
            right >>= 1;
            ++shift;
        }

        return left << shift;
    }

    int secondApproach(int left, int right) {
        while (left < right) {
            right = right & (right - 1);
        }

        return left & right;
    }
public:
    int rangeBitwiseAnd(int left, int right) {
        // return firstApproach(left, right);
        return secondApproach(left, right);
    }
};