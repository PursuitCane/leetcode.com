class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int ans = 0;
        long long sum = 0;
        for (auto item : nums) {
            sum += item;
        }
        long long pre_sum = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            pre_sum += nums[i];
            sum -= nums[i];
            if (pre_sum >= sum) ans++;
        }
        return ans;
        
    }
};
