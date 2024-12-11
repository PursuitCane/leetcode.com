class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 1;
        int i = 0;
        for (int j = 1; j < nums.size(); j++) {
            while (nums[j] - nums[i] > (2 *k)) i++;
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};
