class Solution {
    int firstApproach(int[][] accounts) {
        int max = 0;

        for (int i=0, len = accounts.length; i<len; i++) {
            int temp = 0;

            for (int j=0, siz = accounts[i].length; j<siz; j++) {
                temp += accounts[i][j];
            }

            if (temp > max) {
                max = temp;
            }
        }

        return max;

    }

public
    int maximumWealth(int[][] accounts) {
        return firstApproach(accounts);
    }
}