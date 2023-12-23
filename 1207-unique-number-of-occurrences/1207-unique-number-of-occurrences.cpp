#define MAX 1000
#define MIN -1000
#define SIZ MAX-MIN+1
#define MLN MAX+1

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        // create frequency map
        // xor the frequencies

        int freq_arr[SIZ] = {0}; // array values are -1000 to 1000
        bool uniques[MLN] = {false}; // max array length is 1000 as per constraints
        int len = arr.size();

        for (int i = 0; i < len; i++) {
            freq_arr[arr[i] + MAX]++; // map -1000 to 0 and 0 to 1000 and 1000 to 2000
        }

        for (int i = 0; i < SIZ; i++) {
            if (freq_arr[i]) {
                if (uniques[freq_arr[i]]) {
                    return false; // if visited before --> duplicate
                }

                uniques[freq_arr[i]] = true; // mark as visited
            }
            
        }

        return true;
    }
};