class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26);
        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
        }
        std::priority_queue<int, vector<int>> hp;

        for (int i = 0; i < freq.size(); i++) {
            if (freq[i]) {
                hp.push(i);
            }
        }
        
        string ans;
        while (hp.empty() == false) {
            int index = hp.top(); hp.pop();
            int minimum = min(freq[index], repeatLimit);
            for (int i = 0; i < minimum; i++) {
                ans.push_back('a' + index);
            }
            freq[index] -= minimum;
            if (freq[index]) {
                if (hp.empty()) return ans;
                int second = hp.top(); hp.pop();
                ans.push_back('a' + second);
                freq[second]--;
                hp.push(index);
                if (freq[second]) hp.push(second);
            }
        }
        return ans;
    }
};
