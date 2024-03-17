int speed = []() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 2) {
            return true;
        }

        long temp = num / 2;

        while (temp * temp > num) {
            temp = (temp + num / temp) / 2;
        }

        return (temp * temp == num);
    }
};