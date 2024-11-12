class Solution {
public:
    bool is_prime(int num) {
        int tmp = sqrt(num);
        for (int i = 2; i <= tmp; i++) {
            if (num % i == 0) return false;
        }
        return true;
    }
    bool primeSubOperation(vector<int>& nums) {
        // setup
        vector<bool> prime(1010);
        prime[1] = false;
        prime[2] = true;
        for (int i = 3; i < 1001; i++) {
            prime[i] = is_prime(i);
        }

        // adjust nums
        int pre = 0;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            for (int j = num-1; j>1; j--) {
                if (!prime[j]) continue;
                if (num -j > pre) {
                    nums[i] = num -j;
                    break;
                }
            }
            pre = nums[i];
            //printf("num %d ", nums[i]);
        }

        // check
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= nums[i-1]) return false;
        }
        return true;

        
    }
};
