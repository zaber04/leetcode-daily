const static auto _ = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr; 
}();
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> ladderAlloted;
        int len = heights.size();

        for (int i = 0; i < len - 1; i++) {
            int climb = heights[i+1] - heights[i];

            if (climb <= 0) {
                continue;
            }

            ladderAlloted.push(climb);

            if (ladderAlloted.size() <= ladders) {
                continue;
            }

            bricks -= ladderAlloted.top();
            ladderAlloted.pop();

            if (bricks < 0) {
                return i;
            }
        }

        return len - 1;
    }
};