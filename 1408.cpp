class Solution {
public:
    bool is_substring(string sub, string st) {
        if (sub.size() > st.size()) return false;

        for (int i = 0; i <= st.size() - sub.size(); i++) {
            int count = 0;
            for (int j = 0; j < sub.size(); j++) {
                if (sub[j] == st[i + j]) count++; 
                else break;
            }
            if (count == sub.size()) return true;
        }
        return false;
    }
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words.size(); j++) {
                if (i == j) continue;
                if (is_substring(words[i], words[j])) {
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        return ans;
        
    }
};
