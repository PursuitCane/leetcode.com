class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> in(n);
        int edge_num = edges.size();
        for (auto& edge : edges) {
            in[edge[1]]++;
        }
        unordered_set<int> s;
        int count = 0;
        int ans = -1;
        for (int i = 0; i < n; i++) {
            if (in[i] == 0) {
                count++;
                ans = i;
            }
        }
        if (count != 1) return -1;
        return ans;
    }
};
