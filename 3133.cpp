class Solution {
public:
    long long minEnd(int n, int x) {
        if (n == 1) return x;
        vector<int> ans_bit;
        int base = n - 1;
        while (base | x) {
            if ((x & 1) || (base == 0)){
                ans_bit.push_back(x&1 );
            } 
            else {
                ans_bit.push_back(base & 1);
                base >>= 1;
            }
            x>>=1;
        }

        long long ans = 0;
        long long tmp_mask = 1;
        for (int i = 0; i < ans_bit.size(); i++) {
            if (ans_bit[i] != 0) {
                ans |= tmp_mask;
            }
             tmp_mask <<= 1;
        }

        return ans;
        
    }
};
