class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int freq = 0;
        int m = abs(matrix[0][0]);
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                sum += abs(matrix[i][j]);
                if (matrix[i][j] < 0) freq++;
                m = min(m, abs(matrix[i][j])); 
            }
        }
        if ((freq & 1) == 0) return sum;
        else return sum - 2 * m;
    }
};
