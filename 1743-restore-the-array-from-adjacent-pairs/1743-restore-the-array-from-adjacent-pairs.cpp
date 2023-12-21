class Solution {
public:
// just search for starting vertex with lowest degree in graph then dfs
// Tip: Calculate indegrees and if more than 2 elements have indegrees=1 that means invalid test case. only the two terminal elements should have indegree=1
    vector<int> restoreArray(vector<vector<int>>& pairs) {
        int len = pairs.size();
        unordered_map<int, vector<int>> hashmap;

        for (int i = 0; i < len; i++) {
            // for (a,b) --> put a in b's list, b in a's list
            int left = pairs[i][0];
            int right = pairs[i][1];

            hashmap[left].push_back(right);
            hashmap[right].push_back(left);
        }

        // Each entry in the hashmap has two neighbors or, in case of the ends of the list, only one neighbor. We must keep track of the ends of the list, i.e. a starting point. For simplicity's sake, this can be done by iterating a second time over the resulting hashmap and return the first element that has only one neighbor as the starting point.
        vector<int> result;
        int start = -1e9;
    
        for (auto it: hashmap) {
            if (it.second.size() == 1) {
                result.push_back(it.first);
                // result.push_back(it.second[0]);
                start = it.first;
                break;
            }
        }

        int temp = -1e9;

        for (int i = 1; i <= len; i++) {
            vector<int> right = hashmap[start];
            int next = (right[0] == temp) ? right[1] : right[0];

            result.push_back(next);
            temp = start; // flagging as visited
            start = next; // check neighbours of this new item
        }
        


        return result;
    }
};

/*
Hint with the case, you want to beat 100% of users.

To start this problem, I used Map<Integer,List<Integer>> to store the link of elements. I have already succeeded! But it just beat 70% of users.
Then I transfer to HashTable to store the link of elements. Like this List<Integer> [] . Finally, I beat 100% of the users I wanted. Because the value of elements may be negative. So You need to change them by plus 10^5. Then when returning the result, minus 10^5.
*/