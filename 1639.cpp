class Solution {
public:
    int numWays(vector<string>& words, string target) {
        long long  mod = 1000000000 + 7;
        long long  dp[1010][1010];
        memset(dp, 0, sizeof dp);
        unordered_map<char, int> word_map[1010];
        for (int i = 0; i < words[0].size(); i++) {
            for (int j = 0; j < words.size(); j++) {
                word_map[i][words[j][i]]++;
            }
        }
        for (int i = 0; i < target.size(); i++) {
            int x_max = words[0].size() - target.size() + i + 1;
            for (int j = i; j < x_max; j++) {
                if (i == 0) dp[i][j] = 1;
                dp[i+1][j+1] = dp[i+1][j];
                int count = word_map[j][target[i]];
                if (count != 0) {
                    dp[i + 1][j + 1] += ((dp[i][j] * count) % mod);
                    dp[i + 1][j + 1] %= mod;
                }
            }
        }

        return dp[target.size()][words[0].size()];
    }
};
