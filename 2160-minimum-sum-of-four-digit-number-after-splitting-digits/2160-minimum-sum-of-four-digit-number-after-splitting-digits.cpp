class Solution {
public:
    int minimumSum(int num) {
        string str = to_string(num);
        sort(str.begin(), str.end());

        string str1 = string(1, str[0]) + string(1, str[3]);
        string str2 = string(1, str[1]) + string(1, str[2]);
        
        return stoi(str1) + stoi(str2);
    }
};