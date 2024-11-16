class Solution {
public:
    vector<int> solution1(vector<int>& nums, int k) {
        int size = nums.size();
        vector<int> power(size);
        power[0] = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - nums[i-1] != 1) power[i] = 1;
            else power[i] = power[i-1]+1;
        }
        vector<int> ans;
        for (int i = k-1; i < size; i++) {
            if (power[i] >= k) ans.push_back(nums[i]);
            else ans.push_back(-1);
        }
        return ans;
    }

    vector<int> solution2(vector<int>& nums, int k) {
        int size = nums.size();
        int power = 1;
        vector<int> ans;
        if (k == 1) ans.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - nums[i-1] != 1) power = 1;
            else power++;
            if (i >= k -1) {
                if (power >= k) ans.push_back(nums[i]);
                else ans.push_back(-1);
            }
        }
        return ans;
    }
    vector<int> resultsArray(vector<int>& nums, int k) {
        //return solution1(nums, k);
        return solution2(nums, k);
    }
};
