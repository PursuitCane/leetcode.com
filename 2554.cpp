class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int ans = 0;
        set<int> s;
        int sum = 0;
        for (auto item : banned) {
            if (item <= n) s.insert(item);
        }

        for (int i = 1; i <= n; i++) {
            if (s.count(i) > 0) continue;
            sum += i;
            if (sum > maxSum) break;
            ans++;
        }
        return ans;
    }
};
