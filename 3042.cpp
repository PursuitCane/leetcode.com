class Solution {
public:
    bool check(string& s1, string& s2) {
        if (s1.size() > s2.size()) return false;
        bool mark = true;
        int n1 = s1.size();
        int n2 = s2.size();
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                mark = false;
                break;
            }
            if (s1[i] != s2[n2 - n1 + i]) {
                mark = false;
                break;
            }
        }
        return mark;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if (check(words[i], words[j])) count++;
            }
        }
        return count;
        
    }
};
