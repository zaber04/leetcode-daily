class Solution {
    // brute force check
    int firstApproach(vector<int>& arr) {
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
    
    // binary search
    int secondApproach(vector<int>& arr) {
        int len = arr.size();
        int lim = len / 4;
        vector<int> barriers = {arr[len / 4], arr[len / 2], arr[3 * len / 4]};
        
        for (auto value: barriers) {
            int left = lower_bound(arr.begin(), arr.end(), value) - arr.begin();
            
            int right = upper_bound(arr.begin(), arr.end(), value) - arr.begin();
            
            if (right - left > lim) {
                return value;
            }
        }
        
        return -1;
    }
public:
    int findSpecialInteger(vector<int>& arr) {
        // return firstApproach(arr);
        return secondApproach(arr);
    }
};