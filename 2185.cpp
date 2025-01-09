class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for (int i = 0; i < words.size(); i++) {
            bool mark = true;
            for (int j = 0; j < pref.size(); j++) {
                if (pref[j] != words[i][j]) {
                    mark = false;
                    break;
                }
            }
            if (mark) count++;
        }
        return count;
    }
};
