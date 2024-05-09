#pragma GCC optimize("O3", "unroll-loops")
class Solution {
    vector<int> bucket[512];
    void radixSort(vector<int>& nums) {
        // 1st round
        for (int x : nums)
            bucket[x&511].push_back(x);
        int i = 0;
        for (auto &B : bucket) {
            for (auto v : B)
                nums[i++] = v;
            B.clear();
        }
        // 2nd round
        for (int x : nums)
            bucket[(x>>9)&511].push_back(x);
        i=0;
        for (auto &B : bucket) {
            for (auto v : B)
                nums[i++] = v;
            B.clear();
        }
        // 3rd round
        for (int x : nums)
            bucket[x>>18].push_back(x);
        i=0;
        for (auto &B : bucket) {
            for (auto v : B)
                nums[i++] = v;
        //    B.clear();
        }
    }
public:
    // radix sort
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        const int n = happiness.size();
        radixSort(happiness);
        
        long long sum=0;
        for (int i=0; i<k; i++) {
            long long x=max(0, happiness[n-1-i]-i);
            sum+=x;
        }
            
        return sum;
    }
};

static const auto _ = []() {
  std::ios::sync_with_stdio(false);
  std::cout.tie(nullptr);
  std::cin.tie(nullptr);
  return nullptr;
}();
