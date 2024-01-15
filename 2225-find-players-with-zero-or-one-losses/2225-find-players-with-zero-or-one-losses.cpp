class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int len = matches.size();

        unordered_map<int, int> map;

        for (int i = 0; i < len; i++) {
            if (!map.count(matches[i][0])) {
                map[matches[i][0]] = 0;
            }

            map[matches[i][1]]++;
        }

        vector<int> zeroLoss, oneLoss;

        for (auto [player, loss]: map) {
            if (loss == 0) {
                zeroLoss.push_back(player);
            } else if (loss == 1) {
                oneLoss.push_back(player);
            }
        }

        sort(zeroLoss.begin(), zeroLoss.end());
        sort(oneLoss.begin(), oneLoss.end());

        return { zeroLoss, oneLoss };
    }
};