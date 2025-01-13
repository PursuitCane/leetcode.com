class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char, int> mp;
        for (auto ch : s) {
            mp[ch]++;
        }
        int ans = 0;
        for (auto pair : mp) {
            char ch = pair.first;
            int freq = pair.second;
            while (freq >= 3) {
                freq -= 2;
            }
            ans += freq;
        }
        
        return ans;
        
    }
};
