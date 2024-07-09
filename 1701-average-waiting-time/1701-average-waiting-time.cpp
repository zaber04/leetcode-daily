class Solution {
public:
// Process Scheduling in Operating Systems course. FCFS protocol
// First Come First Serve
    double averageWaitingTime(vector<vector<int>>& customers) {
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        long waitTime = 0;
        int chefTime = 0;
        int len = customers.size();


        for (int i = 0; i < len; i++) {
            chefTime = max(customers[i][0], chefTime) + customers[i][1];
            waitTime += chefTime - customers[i][0];
        }

        return (waitTime * 1.00) / len;
    }
};