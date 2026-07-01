class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        // set arr[0] = 1
        // abs(arr[i] - arr[i+1]) <=1
        
        // 1 <= arr.length <= 10^5
        // 1 <= arr[i] <= 10^9

        // sort the array?
        // iterate through and decrease each element  (if needed)
        // return last value
        sort(arr.begin(), arr.end()); // O (nlogn)

        int len = arr.size();

        arr[0] = 1;

        for (int i = 1; i < len; i++) {
            if ((arr[i] - arr[i-1]) > 1) {
                arr[i] = arr[i-1] + 1;
            }
        }

        return arr[len-1];
    }
};