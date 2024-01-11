class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ret = 0;

        for (int num: left) {
            ret = max(ret, num);
        }

        for (int num: right) {
            ret = max(ret, n - num);
        }

        return ret;
    }
};