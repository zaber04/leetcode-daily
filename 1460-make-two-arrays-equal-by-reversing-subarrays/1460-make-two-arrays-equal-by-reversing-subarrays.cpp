class Solution {
    bool firstApproach(vector<int>& target, vector<int>& arr) {
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());

        return target == arr;
    }

    bool secondApproach(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> arrFreq;

        for (int num : arr) {
            arrFreq[num]++;
        }

        unordered_map<int, int> targetFreq;

        for (int num : target) {
            targetFreq[num]++;
        }

        if (arrFreq.size() != targetFreq.size()) {
            return false;
        }

        for (auto it : arrFreq) {
            if (targetFreq[it.first] != it.second) {
                return false;
            }
        }

        return true;
    }
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        return firstApproach(target, arr);
        // return secondApproach(target, arr);
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();