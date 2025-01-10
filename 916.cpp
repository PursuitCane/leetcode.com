class Solution {
public:
    bool subset(unordered_map<char, int>& m1, unordered_map<char, int>& m2) {
        for (auto pair : m2) {
            char ch = pair.first;
            int cnt = pair.second;
            if (m2[ch] > m1[ch])
                return false;
        }
        return true;
    }

    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        unordered_map<char, int> w2;
        for (int i = 0; i < words2.size(); i++) {
            unordered_map<char, int> tmp;
            for (int j = 0; j < words2[i].size(); j++) {
                tmp[words2[i][j]]++;
            }

            for (auto pair : tmp) {
                char ch = pair.first;
                w2[ch] = max(w2[ch], tmp[ch]);
            }
        }

        for (int i = 0; i < words1.size(); i++) {
            unordered_map<char, int> w1;
            for (int j = 0; j < words1[i].size(); j++) {
                w1[words1[i][j]]++;
            }
            if (subset(w1, w2)) {
                ans.push_back(words1[i]);
            }
        }
        return ans;
    }
};
