class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 1;
        int in_len = 1, de_len = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i-1]) {
                in_len++;
                ans = max(ans, de_len);
                de_len = 1;
            }
            if (nums[i] < nums[i-1]) {
                de_len++;
                ans = max(ans, in_len);
                in_len = 1;
            }
            if (nums[i] == nums[i-1]) {
                ans = max(ans, in_len);
                ans = max(ans, de_len);
                in_len = de_len = 1;
            }
        }
        ans = max(ans, in_len);
        ans = max(ans, de_len);
        return ans;
    }
};
