class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int> presum(nums.size());
        presum[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            presum[i] = presum[i-1] + nums[i];
        }

        vector<int> dp0(nums.size());
        vector<int> index0(nums.size());
        dp0[k - 1] = presum[k - 1];
        index0[k - 1] = 0;
        for (int i = k; i < nums.size(); i++) {
            if (dp0[i - 1] >= presum[i] - presum[i - k]) {
                dp0[i] = dp0[i - 1];
                index0[i] = index0[i - 1];
            } else {
                dp0[i] = presum[i] - presum[i - k];
                index0[i] = i - k + 1;
            }
        }

        vector<int> dp1(nums.size());
        vector<vector<int>> index1(nums.size());
        dp1[2* k - 1] = presum[2 * k - 1];
        index1[2*k -1] = {0, k};
        for (int i = 2*k; i < nums.size(); i++) {
            if (dp1[i - 1] >= presum[i] - presum[i - k] + dp0[i - k]) {
                dp1[i] = dp1[i - 1];
                index1[i] = index1[i - 1];
            } else {
                dp1[i] = presum[i] - presum[i - k] + dp0[i - k];
                index1[i] = {index0[i - k], i - k + 1};
            }
        }

        vector<int> dp2(nums.size());
        vector<vector<int>> index2(nums.size());
        dp2[3*k - 1] = presum[3*k -1];
        index2[3*k -1] = {0, k, 2*k};
        int maxsum = dp2[3*k - 1];
        int index = 3*k -1;
        for (int i = 3*k; i < nums.size(); i++) {
            if (dp2[i-1] >= presum[i] - presum[i - k] + dp1[i - k]) {
                dp2[i] = dp2[i-1];
                index2[i] = index2[i-1];
            } else {
                dp2[i] = presum[i] - presum[i - k] + dp1[i - k];
                index2[i] = {index1[i-k][0], index1[i-k][1], i-k+ 1};
            }
            if (maxsum < dp2[i]) {
                maxsum = dp2[i];
                index = i;
            }
        }
        return index2[index];
    }
};
