class Solution {
public:
    int totalMoney(int n) {
        int weeks = n / 7;
        int minWeekVal = 28; // 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28
        int maxWeekVal = 28 + (weeks - 1) * 7;
        int sum = weeks * (minWeekVal + maxWeekVal) / 2;
        
        int monday = weeks + 1;
        int lastWeek = 0;

        for (int day = 0, dayLimit = n % 7; day < dayLimit; day++) {
            lastWeek += monday + day;
        }

        return sum + lastWeek;
    }
};