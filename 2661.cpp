class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int, pair<int, int>> mp;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                mp[mat[i][j]] = make_pair(i, j);
            }
        }
        vector<int> row(mat.size()), col(mat[0].size());
        for (int i = 0; i < arr.size(); i++) {
            auto pair = mp[arr[i]];
            row[pair.first]++;
            col[pair.second]++;
            if (row[pair.first] == mat[0].size()) return i;
            if (col[pair.second] == mat.size()) return i;
        }
        return 0;
        
    }
};
