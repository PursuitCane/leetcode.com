class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = 0;
        int pre_max = values[0];
        for (int i = 1; i < values.size(); i++) {
            ans = max(ans, pre_max + values[i] - 1);
            pre_max = max(pre_max - 1, values[i]);
        }
        return ans;
        
    }
};
