class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int len = arr.size();

        int maxValue = arr[0];

        for (int i = 1; i < len; i++) {
            maxValue = max(arr[i], maxValue);
        }

        int temp = arr[0];
        int streak = 0;

        for (int i = 1; i < len; i++) {
            int opponent = arr[i];

            if (temp > opponent) {
                streak++;
            } else {
                temp = opponent;
                streak = 1;
            }

            if (streak == k || temp == maxValue) {
                return temp;
            }
        }

        return -1;
    }
};