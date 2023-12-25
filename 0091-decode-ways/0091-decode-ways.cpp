class Solution {
    int firstApproachDynamicHelper(string& str, int position, int length, unordered_map<int, int>& memo) {
        // check if avaiable in memo
        if (memo.find(position) != memo.end()) {
            return memo[position];
        }

        // if starts with 0 --> invalid
        if (str[position] == '0') {
            return 0;
        }

        // reached ending (or about to reach) --> success
        if (position >= length - 1) {
            return 1;
        }

        int ret = firstApproachDynamicHelper(str, position + 1, length, memo);

        if (stoi(str.substr(position, 2)) <= 26) {
            ret += firstApproachDynamicHelper(str, position + 2, length, memo);
        }

        memo[position] = ret;

        return ret;
    }

    int firstApproach(string str) {
        int length = str.length();
        unordered_map<int, int> map;

        return firstApproachDynamicHelper(str, 0, length, map);
    }
public:
    int numDecodings(string str) {
        return firstApproach(str);
    }
};