class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans;
        int next_sum = 0, previous_sum = 0;
        if (k > 0) {
            for (int i = 1; i <= k; i++) {
                next_sum += code[i];
            }
        }
        if (k < 0) {
            for (int i = 1; i <= -k; i++) {
                previous_sum += code[n-i];
            }
        }
        for (int i = 0; i < code.size(); i++) {
            if (k > 0) {
                ans.push_back(next_sum);
                next_sum = next_sum - code[(i+1)%n] + code[(i+1+ k)%n];
            } else if (k < 0) {
                ans.push_back(previous_sum);
                previous_sum = previous_sum + code[i] - code[(i + k+n)%n];
                
            } else {
                ans.push_back(0);
            }
        }
        
        return ans;
        
    }
};
