class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // indexes are 0 to n
        // numbers have to be 0 to n
        // a xor a = 0
        // so, we xor all indexes with all numbers --> cancelled but 1

        int len = nums.size();
        int out = len; // Can you guess why len intead of 0?

        for (int i = 0; i < len; i++) {
            out ^= (i ^ nums[i]);
        }

        return out;
    }

    int missingNumber2(vector<int>& nums) {
        // idea --> sum (0 to n) = n * (n+1) / 2; --> (n+1)P2

        int len = nums.size();

        // use this style for large len
        // int sum = (len & 1) ? (((len + 1) >> 1) * len) : ((len >> 1) * (len + 1));

        int sum = (len * (len+1)) >> 1;

        for (int i = 0; i < len; i++) {
            sum -= nums[i];
        }

        return sum;
    } 

    int missingNumber3(vector<int>& nums) {
        int len = nums.size();
        vector<bool> found(len+1, false);

        for (int i = 0; i < len; i++) {
            found[nums[i]] = true;
        }

        int i = 0;

        for (i = 0; i <= len; i++) {
            if (found[i] == false) {
                break;
            }
        }

        return i;
    }
};