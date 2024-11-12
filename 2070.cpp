class Solution {
public:
    static bool cmp_item(vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    }

    int upper_found(vector<vector<int>>& items, vector<int>& pre_max, int found) {
        if (found < items[0][0]) return 0;

        int l = 0, r = items.size()-1;
        int index = 0;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (items[mid][0] > found) r = mid -1;
            else if (items[mid][0] < found) l = mid + 1;
            else l = mid +1;
        }
        if (items[l][0] > found) l--;
        return pre_max[l];
    }

    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end(), cmp_item);
        vector<int> pre_max(items.size());
        pre_max[0] = items[0][1];
        int index = 1;
        for (int index = 1; index < items.size(); index++) {
            pre_max[index] = max(pre_max[index-1], items[index][1]);
        }

        vector<int> ans;
        for (int i = 0; i < queries.size(); i++) {
            ans.push_back(upper_found(items, pre_max, queries[i]));
        }
        return ans;
        
    }
};
