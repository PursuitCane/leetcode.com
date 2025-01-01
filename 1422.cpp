class Solution {
public:
    int maxScore(string s) {
        vector<int> count(2);
        for (int i = 0; i < s.size(); i++) {
            count[s[i] - '0']++;
        }
        int ans = 0;
        vector<int> tmp(2);
        if (s[0] == '0') {
            ans = 1 + count[1];
            tmp[0]++;
        } else {
            ans = count[1] - 1;
            tmp[1]++;
        }
        for (int i = 1; i < s.size() - 1; i++) {
            if (s[i] == '0') {
                tmp[0]++;
            } else {
                tmp[1]++;
            }
            ans = max(ans, tmp[0] + count[1] - tmp[1]);
        }
        return ans;
        
    }
};
