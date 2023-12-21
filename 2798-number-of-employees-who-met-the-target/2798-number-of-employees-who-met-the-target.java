class Solution {
    public int numberOfEmployeesWhoMetTarget(int[] hours, int target) {
        int ans = 0;

        for (int i=0, len=hours.length; i<len; i++) {
            if (hours[i]>= target) {
                ans++;
            }
        }

        return ans;
    }
}