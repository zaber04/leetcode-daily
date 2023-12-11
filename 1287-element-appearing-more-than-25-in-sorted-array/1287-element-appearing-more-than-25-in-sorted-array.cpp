class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int len = arr.size();
        int lim = len >> 2;
        
        int counter = 0;
        int val = arr[0];

        for (int i = 1; i < len; i++) {
            if (arr[i] == val) {
                counter++;
                if (counter == lim) {
                    break;
                }
            } else {
                counter = 0;
                val = arr[i];
            }
        }
        
        return val;
    }
};