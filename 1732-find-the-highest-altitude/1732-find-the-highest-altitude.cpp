class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int highest = 0, curHeight = 0;

        for (int i: gain) {
            curHeight += i;

            if (curHeight > highest) {
                highest = curHeight;
            }
        }

        return highest;
    }
};