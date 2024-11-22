class Solution {
public:
    bool is_equal(vector<vector<int>>& matrix, int row, vector<int> check) {
        int m = matrix.size(); // row
        int n = matrix[0].size(); // col
        for (int c = 0; c < n; c++) {
            if (matrix[row][c] != check[c]) return false;
        }
        return true;
    }

       int solution1(vector<vector<int>>& matrix) {
        int m = matrix.size(); // row
        int n = matrix[0].size(); // col
        int ans = 0;
        for (int r = 0 ; r < m; r++) {
            vector<int> vec1, vec2;
            // set vec1 & vec2
            for (int c = 0; c < n; c++) {
                vec1.push_back(matrix[r][c]); // all value 0
                vec2.push_back(1 - matrix[r][c]); // all value 1
            }
            int count = 0;
            for (int r_i = 0; r_i < m; r_i++) {
                if (is_equal(matrix, r_i, vec1) || is_equal(matrix, r_i, vec2)) count++;
            }
            ans = max(count, ans);
        }
        return ans;
        
    }

    int solution2(vector<vector<int>>& matrix) {
        int m = matrix.size(); // row
        int n = matrix[0].size(); // col
        unordered_map<string, int> mp;
        
        for (int i = 0; i < m; i++) {
            string st;
            if (matrix[i][0] == 0) {
                for (int j = 0; j < n; j++) {
                    st += to_string(matrix[i][j]);
                }
            } else {
                for (int j = 0; j < n; j++) {
                    st += to_string(1 - matrix[i][j]);
                }
            }
            mp[st]++;
        }
        
        int ans = 0;
        for (auto& pair : mp) {
            ans = max(ans, pair.second);
        }
        return ans;

        
    }

    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        //return solution1(matrix);
        return solution2(matrix);
    }
};
