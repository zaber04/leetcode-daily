class Solution {
private:
    bool unique(int x) {
        array<bool, 10> used{};
        while (x > 0) {
            int digit = x % 10;
            x /= 10;
            if (used[digit]) {
                return false;
            }
            used[digit] = true;
        }
        return true;
    }
public:
    int numberCount(int a, int b) {
        int total = 0;
        for (int x = a; x <= b; x++) {
            if (unique(x)) {
                total++;
            }
        }
        return total;
    }
};