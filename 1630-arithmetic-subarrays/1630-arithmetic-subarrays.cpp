class Solution {
    bool isArithmeticFirst(vector<int>& arr) {
        const int len = arr.size();
        if (len < 3) {
            return true;
        }

        sort(arr.begin(), arr.end());

        const int diff = arr[1] - arr[0];
        

        for (int i = 2; i < len; i++) {
            if (arr[i] - arr[i-1] != diff) {
                return false;
            }
        }

        return true;
    }

    bool isArithmeticSecond(vector<int>& arr) {
        int len = arr.size();

        // max 2 values
        if (len <= 2) {
            return true;
        }

        // duplicate value will pass our test, let's block that
        unordered_set<int> mySet;
        mySet.insert(arr[0]);

        int maxVal = arr[0];
        int minVal = arr[0];

        for (int i = 1; i < len; i++) {
            minVal = min(minVal, arr[i]);
            maxVal = max(maxVal, arr[i]);
            mySet.insert(arr[i]);
        }

        // all values same
        if (maxVal == minVal) {
            return true;
        }

        // must be divisible
        if ((maxVal - minVal) % (len - 1) != 0) {
            return false;
        }

        int diff = (maxVal - minVal) / (len - 1);
        int currVal = minVal + diff;

        // for (int i = 1; i < len; i++) {
        //     if ((arr[i] - minVal) % diff != 0) {
        //         return false;
        //     }
        // }

        while (currVal < maxVal) {
            if (mySet.find(currVal) == mySet.end()) {
                return false;
            }

            currVal += diff;
        }

        return true;
    }

    vector<bool> firstApproach(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int len = nums.size();
        int nel = l.size();

        vector<bool> ans(nel, false);

        for (int i = 0; i < nel; i++) {
            vector<int> sub(nums.begin() + l[i], nums.begin() + r[i] + 1);
            ans[i] = isArithmeticFirst(sub);
        }

        return ans;
    }

    vector<bool> secondpproach(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int len = nums.size();
        int nel = l.size();

        vector<bool> ans(nel, false);

        for (int i = 0; i < nel; i++) {
            vector<int> sub(nums.begin() + l[i], nums.begin() + r[i] + 1);
            ans[i] = isArithmeticSecond(sub);
        }

        return ans;

    }
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        return firstApproach(nums, l, r);
        // return secondpproach(nums, l, r);
    }
};