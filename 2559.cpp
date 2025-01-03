class Solution {
public:
     vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int sum = 0;
        unordered_set<char> s = {'a', 'e', 'i', 'o', 'u'};
        vector<int> presum;
        presum.push_back(0);
        for (int i = 0; i < words.size(); i++) {
            string st = words[i];
            if (s.count(st[0]) && s.count(st[st.size() -1])) {
                presum.push_back(presum[i] + 1);
            } else {
                presum.push_back(presum[i]);
            }
        }

        vector<int> ans;
        for (int i = 0; i < queries.size(); i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            ans.push_back(presum[r + 1] - presum[l]);
        }
        return ans;
        
    }
};
