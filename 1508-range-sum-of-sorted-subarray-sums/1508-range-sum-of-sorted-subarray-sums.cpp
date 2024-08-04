class Solution {
    const int MOD = 1e9+7;

    int firstApproach(vector<int>& nums, int n, int left, int right) {
        vector<int> subSums;
        int len = nums.size();

        for (int i = 0; i < len; i++) {
            int temp = nums[i];
            subSums.push_back(temp);

            for (int j = i + 1; j < len; j++) {
                temp += nums[j];
                subSums.push_back(temp);
            }
        }

        sort(subSums.begin(), subSums.end());

        unsigned long long int llu = 0;

        for (int i = left - 1; i < right; i++) {
            llu += subSums[i];
        }

        return (int)(llu % MOD);
    }

    int secondApproach(vector<int>& nums, int n, int left, int right) {
        using iPair = pair<int, int>;
        int len = nums.size();

        priority_queue<iPair, vector<iPair>, greater<iPair>> heap;

        // one-sized subarray sum
        for (int i = 0; i < len; i++) {
            heap.push({nums[i], i});
        }

        unsigned long long int llu = 0;

        for (int i = 1; i <= right; i++) {
            // pop the smallest element which represents the smallest subarray sum
            auto temp = heap.top();
            heap.pop();

            if (i >= left) {
                llu += temp.first;
            }

            // this subarray could be part of a larger subarray.
            // hence we expand the subarray by one element.
            if (temp.second < len - 1) {
                temp.first += nums[++temp.second];
                heap.push(temp);
            }
        }

        return (int)(llu % MOD);
    }
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        return firstApproach(nums, n, left, right);
        // return secondApproach(nums, n, left, right);
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();