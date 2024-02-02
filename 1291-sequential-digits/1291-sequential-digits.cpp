class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        const string choice = "123456789";

        int minSize = to_string(low).size(), maxSize = to_string(high).size();

        vector<int> result;

        for (int i = minSize; i <= maxSize; i++) {
            for (int j = 0; j <= 9 - i; j++) {
                int temp = stoi(choice.substr(j, i));

                if (low <= temp && temp <= high) {
                    result.push_back(temp);
                }
            }
        }

        return result;
    }
};