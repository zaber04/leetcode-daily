class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int small = min(prices[0], prices[1]);
        int large = max(prices[0], prices[1]);

        for (int i = 2, len = prices.size(); i < len; i++) {
            int price = prices[i];

            if (price < small) {
                large = small;
                small = price;
            } else if (price < large) {
                large = price;
            }
        }

        int cost = large + small;

        return cost > money ? money : money - cost;
    }
};