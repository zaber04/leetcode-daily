class Solution {
    vector<int> firstApproach(vector<int>& nums) {
        vector<int> positives;
        vector<int> negatives;

        for (int num : nums) {
            if (num > 0) {
                positives.push_back(num);
            } else {
                negatives.push_back(num);
            }
        }

        vector<int> out;

        for (int i = 0, len2 = (nums.size() >> 1); i < len2; i++) {
            out.push_back(positives[i]);
            out.push_back(negatives[i]);
        }

        return out;
    }

    vector<int> secondApproach(vector<int>& nums) {
        int len = nums.size();
        vector<int> out(len, 0);

        int positivePointer = 0, negativePointer = 1;
        
        for (int num : nums) {
            if (num > 0) {
                out[positivePointer] = num;
                positivePointer += 2;
            } else {
                out[negativePointer] = num;
                negativePointer += 2;
            }
        }

        return out;
    }
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        // return firstApproach(nums);
        return secondApproach(nums);
    }
};