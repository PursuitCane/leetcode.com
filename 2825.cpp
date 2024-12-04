class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int len1 = str1.size(), len2 = str2.size();
        int j = 0;
        for (int i = 0; i < len1; i++) {
            if (str1[i] == str2[j] || (str1[i] == 'z' && str2[j] == 'a')) j++;
            else if ((str1[i] + 1) == str2[j]) j++;
            if (j == len2) return true;
        }
        return false; 
    }
};
