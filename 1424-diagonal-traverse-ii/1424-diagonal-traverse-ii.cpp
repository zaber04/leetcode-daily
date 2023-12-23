#define Tripple tuple<int, int, int>
class Solution {
    static bool compareTuples(Tripple t1, Tripple t2)
    {
        return (get<0>(t1) <= get<0>(t2));
    }
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        // To collect the cells on each diagonal in the correct order, 
        // we will iterate through each row from left to right 
        // starting with the bottom row. 

        /*      
        [0] = [(0, 0)]
        [1] = [(1, 0), (0, 1)]
        [2] = [(2, 0), (1, 1), (0, 2)]
        [3] = [(3, 0), (2, 1), (1, 2), (0, 3)]
        [4] = [(4, 0), (3, 1), (2, 2), (1, 3), (0, 4)]
        [5] = [(5, 0), (4, 1), (3, 2), (2, 3), (1, 4), (0, 5)]
        [6] = [(6, 0), (5, 1), (4, 2), (3, 3), (2, 4), (1, 5), (0, 6)]
        [7] = [(7, 0), (6, 1), (5, 2), (4, 3), (3, 4), (2, 5), (1, 6), (0, 7)]
        [8] = [(7, 1), (6, 2), (5, 3), (4, 4), (3, 5), (2, 6), (1, 7)]
        [9] = [(7, 2), (6, 3), (5, 4), (4, 5), (3, 6), (2, 7)]
        [10] = [(7, 3), (6, 4), (5, 5), (4, 6), (3, 7)]
        [11] = [(7, 4), (6, 5), (5, 6), (4, 7)]
        [12] = [(7, 5), (6, 6), (5, 7)]
        [13] = [(7, 6), (6, 7)]
        [14] = [(7, 7)]
        */


        unordered_map<int, vector<int>> groups;
        vector<int> ret;
        int rowLen = nums.size();
        int maxDiagonal = 0;

        for (int row = rowLen - 1; row >= 0; row--) {
            for (int col = 0, colLen = nums[row].size(); col < colLen; col++) {
                int rowCol = row + col;
                groups[rowCol].push_back(nums[row][col]);
                maxDiagonal = max(maxDiagonal, rowCol);
            }
        }

        int curr = 0;
        while (groups.find(curr) != groups.end()) {
            for (int num : groups[curr]) {
                ret.push_back(num);
            }
            
            curr++;
        }

        return ret;
    }
};