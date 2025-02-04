class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = nums[0];
        int pre_sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i-1]) {
                pre_sum += nums[i];
            } else {
                ans = max(ans, pre_sum);
                pre_sum = nums[i];
            }
        }
        ans = max(ans, pre_sum);
        return ans;

        
        
    }
};
