class Solution {
    vector<int> weightedSum;
    int weightMax;
    int len;
public:
    Solution(vector<int>& w) {
        // construct weighted sum
        // input [1, 5, 2] will generate [1, 6, 8]
        // then find generate random between min_weight & max weight
        // 1 belongs to index 0
        // 2-6 belongs to index 1
        // 7-8 belongs to index 2
        // we find index using binary search
        this->weightMax = 0;
        this->len = w.size();
        for (int i = 0; i<len; i++) {
            this->weightMax += w[i];
            weightedSum.push_back(this->weightMax);
        }
    }

    int randomInt(int min, int max) {
        std::random_device                  rand_dev;
        std::mt19937                        generator(rand_dev());
        std::uniform_int_distribution<int>  distr(min, max);

        return distr(generator);
    }
    
    int pickIndex() {
        // generate a weight
        int randomWeight = this->randomInt(0, this->weightMax - 1);

        // find where this random number would have been placed
        // insertion point - 1 is the answer
        int left = 0;
        int right = this->len-1; 

        while (left < right) {
            int mid = (left + right) >> 1;

            if (weightedSum[mid] > randomWeight) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */