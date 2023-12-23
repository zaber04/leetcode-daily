class Solution {
    int firstApproach(vector<int>& arr) {
        int len = arr.size();

        if (len == 1) {
            return 0;
        }

        unordered_map<int, int> map;

        for (int i = 0; i < len; i++) {
            map[arr[i]]++;
        }

        int ret = 0;
        for (auto it:map) {
            if (map.find(it.first + 1) != map.end()) {
                ret += it.second;
            }
        }

        return ret;
    }

    int secondApproach(vector<int>& arr) {
        int len = arr.size();

        if (len == 1) {
            return 0;
        }

        vector<int> freq(1001, 0);

        for (int i = 0; i < len; i++) {
            freq[arr[i]]++;
        }

        // freq[i] --> contains count of i in arr
        // freq[i+1] --> contains count of i+1 in arr
        int ret = 0;
        for (int i = 0; i < 1000; i++) {
            if (freq[i+1] > 0) {
                ret += freq[i];
            }
        }

        return ret;
    }
public:
    int countElements(vector<int>& arr) {
        return firstApproach(arr);
        // return secondApproach(arr);
    }
};