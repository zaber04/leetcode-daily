class Solution {
public:
    static int beautifulSubsets(vector<int>& nums, const int k) {
        const int n = nums.size();
        auto [x_min, x_max]=minmax_element(nums.cbegin(), nums.cend());
        const int M = *x_max - *x_min + 1;
        const int q = (M + k) / k; // ceil((M+1)/k)
        
        // Initialize the frequency array
        char freq[k][q+1];
        memset(freq, 0, sizeof(freq));
        
        for (auto x : nums) {
            auto [i, r] = div(x-*x_min, k);
            freq[r][i]++;
        }
        
        int ans = 1; // Start with 1 fpr the product
        for (int r = 0; r < k; r++) {
            int prev = 1, curr = 1;
            for (int i = 0; i < q; i++) {
                int take = (1 << freq[r][i]) - 1;
                if (i > 0) take *= prev;
                else take *= curr;
                prev = curr;
                curr = curr + take;
            }
            ans *= curr;
        }

        
        return ans-1; //exclude the empty set
    }
};


auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();