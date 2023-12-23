int speed_up = [] {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
    int firstApproach(vector<int>& piles) {
        int len = piles.size();

        sort(piles.begin(), piles.end());

        int ans = 0;
        for (int i = (len / 3); i < len-1; i += 2) {
            ans += piles[i];
        }

        return ans;
    }

    int secondApproach(vector<int>& piles) {
        int len = piles.size();
        int max = 0;

        for (int i = 0; i < len; i++) {
            if (piles[i] > max) {
                max = piles[i];
            }
        }

        vector<int> freq(max+1, 0);
        
        for (int i = 0; i < len; i++) {
            freq[piles[i]]++;
        }

        int ans = 0;
        int turnCount = len / 3;

        int i = max;
        int turn = 1;

        while (turnCount) {
            if (freq[i]) {
                if (turn == 1) {
                    turn = 0;
                } else {
                    turnCount--;
                    turn = 1;
                    ans += i;
                }
                freq[i]--;
            } else {
                i--;
            }
        }

        return ans;
    }
public:
    int maxCoins(vector<int>& piles) {
        // return firstApproach(piles);
        return secondApproach(piles);
    }
};