class Solution {
public:
    int ans;
    void dfs(vector<int>& nums, int target, int index, int sum) {
        if (index == nums.size()) {
            if (sum == target) ans++;
            return;
        }
        sum += nums[index];
        dfs(nums, target, index + 1, sum);
        sum -= nums[index];
        sum -= nums[index];
        dfs(nums, target, index + 1, sum);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        ans = 0;
        dfs(nums, target, 0, 0);
        return ans;
    }
};
