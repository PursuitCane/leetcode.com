class Solution {
public:
    vector<vector<char>> solution1(vector<vector<char>>& box) {
        int m = box.size(), n = box[0].size();
        /* gravity 1
        for (int i = 0; i < m; i++) {
            for (int j = n - 2; j >=0; j--) {
                if (box[i][j] == '#') {
                    int k = j;
                    while (k < n - 1 && box[i][k + 1] == '.') {
                        k++;
                    }
                    if (k > j) {
                        box[i][k] = '#';
                        box[i][j] = '.';
                    }
                }
            }
        }*/

        // gravity 2
        for (int i = 0; i < m; i++) {
            int bottom = n -1;
            for (int j = n - 1; j >=0; j--) {
                if (box[i][j] == '#') {
                    box[i][bottom] = '#';
                    if (j != bottom) box[i][j] = '.'; 
                    bottom--;         
                } else if (box[i][j] == '*') bottom = j - 1;
            }
        }
        // rotated
        vector<vector<char>> ans;
        for (int i = 0; i < n; i++) {
            vector<char> tmp;
            for (int j = 0; j < m; j++) {
                tmp.push_back(box[m - j -1][i]);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
    vector<vector<char>> solution2(vector<vector<char>>& box) {
        int m = box.size(), n = box[0].size();
        vector<vector<char>> ans(n, vector<char>(m, '.'));
        for (int i = 0; i < m; i++) {
            int bottom = n -1;
            for (int j = n - 1; j >=0; j--) {
                if (box[i][j] == '#') {
                    ans[bottom][m - i -1] = '#';
                    bottom--;         
                } else if (box[i][j] == '*') {
                    ans[j][m - i -1] = '*';
                    bottom = j - 1;
                }
            }
        }
        return ans;
    }

    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        //return solution1(box);
        return solution2(box);
    }
};
