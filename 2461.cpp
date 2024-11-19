class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0, sum = 0;
        unordered_map<int, int> count_map;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            count_map[nums[i]]++;

            if (i >= k) {
                sum -= nums[i - k];
                count_map[nums[i - k]]--;
                if (count_map[nums[i - k]] == 0)
                    count_map.erase(nums[i - k]);
            }

            if (i >= k - 1) {
                if (count_map.size() == k)
                    ans = max(ans, sum);
            }
        }

        return ans;
    }
        
 };
