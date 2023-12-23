#define iPair pair<int, int>

class Solution {
    bool firstApproach(string path) {
        unordered_map<char, iPair> position;

        // store all possible movements
        position['N'] = {0, 1};
        position['S'] = {0, -1};
        position['E'] = {1, 0};
        position['W'] = {-1, 0};

        unordered_set<string> visited;
        visited.insert("0,0");

        int row = 0, col = 0;

        for (char c : path) {
            iPair temp = position[c]; // get the possible movements

            row += temp.first;
            col += temp.second;

            // check if new value part of visited set
            string rowCol = to_string(row) + "," + to_string(col);

            if (visited.find(rowCol) != visited.end()) {
                return true;
            }

            visited.insert(rowCol);
        }

        return false;
    }
public:
    bool isPathCrossing(string path) {
        return firstApproach(path);
    }
};