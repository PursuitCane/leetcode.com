class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < n; i++) {
            int item = arr[i];
            m[item].push_back(i);
        }
        for (int i = 0; i < n; i++) {
            int item = arr[i];
            if (m[item*2].size() > 1) return true;
            if (m[item*2].size() == 1 && m[item*2][0] != i) return true;
        }
        return false;
    }
};
