class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> ans;
        int size = nums.size();
        int base = nums[0];
        for (int i = 1; i <size; i++) {
            base ^= nums[i];
        }
        int max_k = (1 << maximumBit) - 1;
        for (int i = 0; i < size; i++) {
            //printf("base %d max_k %d ", base, max_k);
            ans.push_back(base ^ max_k);
            base ^= nums[size -i-1];
        }
        return ans;
    }
};
