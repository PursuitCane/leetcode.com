class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int ans = 0;
        int mask = 1;
        int loop = 25;
        while (loop--) {
            int count = 0;
            for (auto num : candidates) {
                if (num & mask) count++;
            }
            if (count > ans) ans = count;
            mask <<= 1;
        }
        return ans;
        
    }
};
