class Solution {
public:
    int maximumLength(string s) {
        int ans = 0;
        int vec[26][55];
        memset(vec, 0, sizeof vec);
        vec[s[0] - 'a'][1] = 1;
        int freq = 1;
        int len = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i-1]) {
                freq++;
                for (int j = freq; j >=1; j--)
                    vec[s[i] - 'a'][j]++;
                len = max(len, freq);
            } else {
                freq = 1;
                vec[s[i] - 'a'][freq]++;
            } 
        }
        for (int i = len; i >= 1; i--) {
            for (int j = 0; j < 26; j++) {
                if (vec[j][i] >= 3) return i;
            }
        }
        return -1;
        
    }
};
