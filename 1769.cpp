class Solution {
public:
    vector<int> minOperations(string boxes) {
        int suffix_sum = 0;
        int suffix_cnt = 0;
        for (int i = 1; i < boxes.size(); i++) {
            if (boxes[i] == '1') {
                suffix_cnt++;
                suffix_sum += i;
            }
        }
        vector<int> ans;
        ans.push_back(suffix_sum);
        int prefix_sum = 0;
        int prefix_cnt = 0;
        if (boxes[0] == '1') {
            prefix_sum++;
            prefix_cnt++;
        }
        for (int i = 1; i < boxes.size(); i++) {
            suffix_sum -= suffix_cnt;
            ans.push_back(suffix_sum + prefix_sum);
            if (boxes[i] == '1') {
                suffix_cnt--;
                prefix_cnt++;
            }
            prefix_sum += prefix_cnt;
        }
        return ans;
        
    }
};
