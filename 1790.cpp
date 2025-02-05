class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        string swap1, swap2;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                swap1 += s1[i];
                swap2 +=s2[i];
            }
        }
        if (swap1.empty()) return true;
        if (swap1.size() > 2) return false;
        if (swap1[0] != swap2[1]) return false;
        if (swap1[1] != swap2[0]) return false;
        return true;
    }
};
