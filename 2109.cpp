class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans;
        int index = 0;
        int size = spaces.size();
        for (int i = 0; i < s.size(); i++) {
            if (index < size && i == spaces[index]) {
                index++;
                ans += ' ';
                ans += s[i];
            } else ans += s[i];
        }
        return ans;
    }
};
