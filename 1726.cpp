class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int ans = 0;
        map<int, int> mp;
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int tmp = nums[i] * nums[j];
                mp[tmp]++;
                int count = mp[tmp];
                if (count >= 2) {
                    ans += count * (count-1) / 2;
                    ans -= (count-1)*(count-2) /2;
                 }
            }
        }

        ans *= 8;
        return ans;
        
    }
};
