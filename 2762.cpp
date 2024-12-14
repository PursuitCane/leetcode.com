class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        
        deque<pair<int, int>> min_dq, max_dq;
        min_dq.push_back(make_pair(nums[0], 0));
        max_dq.push_back(make_pair(nums[0], 0));

        int j = 0;
        for (int i = 0; i < n; i++) {
            while (min_dq.front().second < i) {
                min_dq.pop_front();
            }
            int mi_num = min_dq.front().first;

            while (max_dq.front().second < i) {
                max_dq.pop_front();
            }
            int ma_num = max_dq.front().first;
            
            if (j == n) {
                if (ma_num - mi_num <= 2) {
                    ans += j - i;
                }
                continue;
            }

            while (ma_num - mi_num <= 2) {
                j++;
                if (j == n) break;
                // update min dq
                while (min_dq.empty() == false && min_dq.back().first >= nums[j]) min_dq.pop_back();
                min_dq.push_back(make_pair(nums[j], j));

                // update max dq
                while (max_dq.empty() == false && max_dq.back().first <= nums[j]) max_dq.pop_back();
                max_dq.push_back(make_pair(nums[j], j));

                mi_num = min_dq.front().first;
                ma_num = max_dq.front().first;
            }

            ans += j - i;
        }

        return ans;
    }
};
