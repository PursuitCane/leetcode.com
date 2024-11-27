class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n,
                                             vector<vector<int>>& queries) {
        vector<vector<int>> m(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                m[i][j] = -1;
                if (j > i) m[i][j] = j - i;
            }
            m[i][i] = 0;
        }

        vector<int> ans;
        for (auto& query : queries) {
            int u = query[0], v = query[1];
            m[u][v] = 1;
            for (int i = 0; i <= u; i++) {
                m[i][v] = min(m[i][v], m[i][u] + m[u][v]);
                for (int j = v; j < n; j++) {
                    m[i][j] = min(m[i][j], m[i][v] + m[v][j]);
                }
            }
            
            ans.push_back(m[0][n - 1]);
        }
        return ans;
    }
};
