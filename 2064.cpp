class Solution {
public:
    bool is_distributed(int num, int n, vector<int>& quantities) {
        int count = 0;
        for (auto quan : quantities) {
            count += quan / num;
            if (quan % num) count++;
        }
        return count <= n;

    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int max_quan = 0;
        for (auto quan : quantities) {
            max_quan = max(max_quan, quan);
        }
        int l = 1, r = max_quan;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (is_distributed(mid, n, quantities)) r = mid;
            else l = mid + 1;
         }
         return l;
        
    }
};
