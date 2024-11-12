class Solution {
public:
    void add_bits(vector<int>& bits, int num) {
        int count = 0;
        while (num) {
            if (num&1) bits[count]++;
            num >>= 1;
            count++;
        }
    }

    void del_bits(vector<int>& bits, int num) {
        int count = 0;
        while (num) {
            if (num&1) bits[count]--;
            num >>= 1;
            count++;
        }

    }

    int cal_bits(vector<int>& bits) {
        int ans = 0;
        for (int i = 0; i < bits.size(); i++)
            if (bits[i]) ans += (1<<i);
        return ans;

    }

    int minimumSubarrayLength(vector<int>& nums, int k) {
        if (k == 0) return 1;
        int num = 0;
        for (auto item : nums) {
            num |= item;
        }
        if (num < k) return -1;


        vector<int> bits(32);
        int i = 0, j = 0;
        int ans = nums.size();
        add_bits(bits, nums[0]);
        while (i < nums.size() && j < nums.size()) {
            if (cal_bits(bits) >= k) {
                ans = min(ans, j -i +1);
                del_bits(bits, nums[i]);
                i++;
                continue;
            }
            j++;
            if (j < nums.size()) add_bits(bits, nums[j]);


        }
        return ans;
    }
};
