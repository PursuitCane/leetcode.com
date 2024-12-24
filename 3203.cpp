class Solution {
public:
    int build(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n + 1);
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n+1);
        queue<int> que;
        que.push(0);
        int end = 0;
        visited[0] = true;
        while (!que.empty()) {
            end = que.front();
            int size = que.size();
            while (size--) {
                int node = que.front(); que.pop();
                for (int i = 0; i < adj[node].size(); i++) {
                    if (visited[adj[node][i]]) continue;
                    que.push(adj[node][i]);
                    visited[adj[node][i]] = true;
                }
            }
        }

        std::fill(visited.begin(), visited.end(), false);
        que.push(end);
        visited[end] = true;
        int dia = 0;

        while (!que.empty()) {
            dia++;
            int size = que.size();
            while (size--) {
                int node = que.front(); que.pop();
                for (int i = 0; i < adj[node].size(); i++) {
                    if (visited[adj[node][i]]) continue;
                    que.push(adj[node][i]);
                    visited[adj[node][i]] = true;
                }
            }
        }

        return --dia;
        
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int dia_1 = build(edges1);
        int dia_2 = build(edges2);
        
        return max(dia_1/2 + dia_1%2 + dia_2/2 + dia_2 %2 + 1, max(dia_1, dia_2));
    }
};
