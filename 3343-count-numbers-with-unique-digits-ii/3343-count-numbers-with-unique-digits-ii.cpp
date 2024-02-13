class Solution {
public:
    int numberCount(int a, int b) {
        int total = 0;

        for (int i = a; i <= b; i++) {
            unordered_set<char> hashset;

            string num = to_string(i);
            total++;

            for (int j = 0, len = num.size(); j < len; j++) {
                if (!hashset.contains(num[j])) {
                    hashset.insert(num[j]);
                } else {
                    total--;
                    break;
                }
            }
        }

        return total;
    }
};