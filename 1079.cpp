class Solution {
public:
    unordered_set<string> st;
    void dfs(unordered_map<char, int>& mp, int dst, string& tmp) {
        if (dst == tmp.size()) {
            st.insert(tmp);
            return;
        }
        for (auto item : mp) {
            char ch = item.first;
            int cnt = item.second;
            if (cnt == 0) continue;
            mp[ch]--;
            tmp += ch;
            dfs(mp, dst, tmp);
            mp[ch]++;
            tmp.pop_back();
        }
    }
    int numTilePossibilities(string tiles) {
        unordered_map<char, int> mp;
        string tmp;
        for (auto ch : tiles) {
            mp[ch]++;
        }
        int n = tiles.size();
        for (int i = 1; i <= n; i++) {
            dfs(mp, i, tmp);
        }
        return st.size();
        
    }
};
