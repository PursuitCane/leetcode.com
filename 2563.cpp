class Solution {
public:
    int lower_bound(vector<int>& nums, int i, int lower) {
        //printf("i %d lower ", i);
        lower = lower - nums[i];
        int l = i + 1;
        int r = nums.size()-1;
        if (nums[r] < lower) return -1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] < lower) l = mid + 1;
            else r = mid;
        }
        return l;
    }

    int upper_bound(vector<int>& nums, int i, int upper) {
        //printf("i %d upper ", i);
        upper = upper - nums[i];
        int l = i + 1;
        int r = nums.size() -1;
        if (nums[l] > upper) return -1;
        while (l < r) {
            int mid = ((l + r) >> 1) + ((l + r) & 1);
            if (nums[mid] > upper) r = mid -1;
            else l = mid;
        }
        return l;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long ans = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            int l = lower_bound(nums, i, lower);
            int r = upper_bound(nums, i, upper);
            if (l != -1 && r != -1) ans += r - l + 1;
        }
        return ans;

        
    }
};
