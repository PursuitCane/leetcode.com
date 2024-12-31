class Solution {
public:
    int find(vector<int>& days, vector<int>& dp, int t, int d) {
        int begin = days[t] - d + 1;
        if (days[0] >= begin) return 0;
        while (t--) {
            if (days[t] < begin)
                return dp[t];
        }
        return 0;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size());
        for (int i = 0; i < days.size(); i++) {           
            int cost = find(days, dp, i, 1);
            dp[i] = cost + costs[0];

            cost = find(days, dp, i, 7);
            dp[i] = min(dp[i], cost + costs[1]);

            cost = find(days, dp, i, 30);
            dp[i] = min(dp[i], cost + costs[2]);

        }
        return dp.back();
    }
};
