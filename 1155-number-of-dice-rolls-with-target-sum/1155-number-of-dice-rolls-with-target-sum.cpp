class Solution {
public:
    int numRollsToTarget(int diceCount, int faceCount, int target) {
        const int bymod = 1000000007;

        // have to make "t" using "n" dices.
        // essentially distribute "t" number of 1's into "n" groups while each group has atleast 1 member.
        vector<vector<int>> memo(diceCount + 1, vector<int>(target + 1, 0));

        memo[diceCount][target] = 1;

        for (int diceIndex = diceCount - 1; diceIndex >= 0; diceIndex--) {
            for (int tempSum = 0; tempSum <= target; tempSum++) {
                int options = 0;

                // possible face value for current dice
                for (int diceValue = 1; diceValue <= min(faceCount, target - tempSum); diceValue++) {
                    options = (options + memo[diceIndex + 1][tempSum + diceValue]) % bymod;
                }

                memo[diceIndex][tempSum] = options;
            }
        }

        return memo[0][0];
    }
};