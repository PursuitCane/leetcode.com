class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        // init
        bool mark[m][n], mark_wall[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mark[i][j] = mark_wall[i][j] = false;

            }
        }

        for (auto& wall : walls) {
            int r = wall[0], c = wall[1];
            mark_wall[r][c] = true;
            mark[r][c] = true;
        }

        for (auto& guard : guards) {
            int r = guard[0], c = guard[1];
            mark_wall[r][c] = true;
            mark[r][c] = true;
        }

        //iterator
        vector<vector<int>> dir;
        dir.push_back({-1, 0});
        dir.push_back({0, -1});
        dir.push_back({1, 0});
        dir.push_back({0, 1});

        for (auto& guard : guards) {
            int r = guard[0], c = guard[1];
            //printf("guard r %d c %d\n", r, c);
            for (int i = 0; i < dir.size(); i++) {
                int cur_r = r + dir[i][0], cur_c = c + dir[i][1];
                //printf("check r %d c %d\n", r, c);
                while (cur_r >= 0 && cur_r < m &&
                    cur_c >= 0 && cur_c < n && mark_wall[cur_r][cur_c] == false) {
                        mark[cur_r][cur_c] = true;
                        cur_r += dir[i][0];
                        cur_c += dir[i][1];
                        //printf("check r %d c %d\n", r, c);
                    }
            }
        }



        // count
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mark[i][j] == false) ans++;
            }
        }

        return ans;

        
    }
};
