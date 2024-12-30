class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1 + max(zero, one));
        int mod = 1000000000 + 7;
        dp[0] = 1;
        for (int i = 0; i < high + 1; i++) {
            dp[i + zero] += dp[i];
            dp[i + zero] %= mod;
            dp[i + one] += dp[i];
            dp[i + one] %= mod;
        }
        int ans = 0;
        for (int i = low; i < high + 1; i++) {
            ans += dp[i];
            ans %= mod;
        }

        return ans;
        
    }
};
