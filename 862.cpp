class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        vector<long long> presum;
        presum.push_back(0);
        int ans = -1;
        deque<int> dq;
        dq.push_back(0);
        for (int i = 0; i < nums.size(); i++) {
            presum.push_back(presum[i] + nums[i]);

            // check front
            while (!dq.empty() && presum[i+1] - presum[dq.front()] >= k) {
                if (ans == -1) ans = i + 1 -  dq.front();
                else ans = min(ans, i + 1 - dq.front());
                dq.pop_front();
            }

            // update dq
            while (!dq.empty() && presum[dq.back()] >= presum[i+1]) {
                dq.pop_back();
            }

            dq.push_back(i+1);
        }
        return ans;
        
    }
};
