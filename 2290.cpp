class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
               auto minHeapCompare = [](pair<int, int> left, pair<int, int> right) {
            return left.second > right.second; // 自定义比较器，建立最小堆
        };
        std::priority_queue<pair<int, int>, std::vector<pair<int, int>>,
                            decltype(minHeapCompare)>
            heap(minHeapCompare);

        int m = grid.size(), n = grid[0].size();
        int goal = m * n - 1;
        vector<int> visit(goal + 1, -1);
        visit[0] = 0;
        // init node
        int dst = 0, len = 0;
        pair<int, int> path;
        path = make_pair(dst, len);
        heap.push(path);
        vector<vector<int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        // dijkstra
        while (heap.empty() == false) {
            path = heap.top();
            heap.pop();
            dst = path.first, len = path.second;
            if (dst == goal) return len;
            if (visit[dst] != -1 && visit[dst] < len) continue;
            for (int i = 0; i < dir.size(); i++) {
                int row = dst / n, col = dst % n;
                row += dir[i][0]; col += dir[i][1];
                if (row >= m || row < 0 || col >= n || col < 0) continue;
                int new_dst = row * n + col;
                int new_len = len;
                if (grid[row][col]) new_len++;
                if (visit[new_dst] == -1 || visit[new_dst] > new_len) {
                    visit[new_dst] = new_len;
                    path = make_pair(new_dst, new_len);
                    heap.push(path);
                }                
            }
        }
        return 0;
    }
};
