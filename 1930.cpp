class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int count = 0;
        unordered_set<char> sub[26];
        unordered_map<char, int> curr;
        unordered_map<char, int> freq[26];
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            curr[ch]++;
            if (freq[ch - 'a'].size() == 0) {
                freq[ch - 'a'] = curr;
                continue;
            }
            if (freq[ch - 'a'][ch] > 1) {
                if (sub[ch - 'a'].count(ch) == 0) {
                    sub[ch - 'a'].insert(ch);
                    count++;
                    //printf("%c%c%c\n", ch, ch, ch);
                }
            }
            if (sub[ch - 'a'].size() == 26)
                continue;
            for (int j = 0; j < 26; j++) {
                if (freq[ch - 'a'][j + 'a'] == curr[j + 'a'])
                    continue;
                if (ch == j + 'a') continue; 
                if (sub[ch - 'a'].count(j + 'a'))
                    continue;
                sub[ch - 'a'].insert(j + 'a');
                count++;
                //printf("%c%c%c\n", ch, j + 'a', ch);
            }

            freq[ch - 'a'] = curr;
        }
        return count;
    }
};
