class Solution {
public:
    int takeCharacters(string s, int k) {
        if (k == 0) return 0;
        vector<int> count = {0, 0, 0};
        int n = s.size();
        int j = -1;
        for (int i = n-1; i >= 0; i--) {
            count[s[i] - 'a']++;
            if (j < 0 && count[0] >=k && count[1] >=k && count[2] >=k) {
                j = i;
                break;
            }
        }
        if (j < 0) return -1;
        int ans = n - j ;
        // iterator
        for (int i = 0; i < n; i++) {
            count[s[i]- 'a']++;
            while ( j < n && (count[s[j]- 'a'] -1) >= k) {
                count[s[j]- 'a']--;
                j++;
            }
            ans = min(ans, i + 1 + n - j);
        }

        return ans;
    }
};
