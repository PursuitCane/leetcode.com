class Solution {
public:
    set<char> st;
    string ans;
    void dfs(string& pattern, int index, string prefix) {
        if (ans.size()) return;
        if (index > pattern.size()) {
            bool check = true;
            for (int i = 0; i < pattern.size(); i++) {
                if (pattern[i] == 'D') {
                    if (prefix[i] < prefix[i+1]) {
                        check = false;
                        break;
                    }
                } else {
                    if (prefix[i] > prefix[i+1]) {
                        check = false;
                        break;
                    }
                }
            }
            if (check) ans = prefix;
            return;
        }

        for (int i = 1; i < 10; i++) {
            char ch = '0' + i;
            if (st.count(ch)) continue;
            st.insert(ch);
            dfs(pattern, index+1, prefix+ch);
            st.erase(ch);
        }
        
    }
    string solution1(string& pattern) {
        dfs(pattern, 0, "");
        return ans;
    }

    string solution2(string& pattern) {
        stack<int> st;
        string ans;
        for (int i = 0; i <= pattern.size(); i++) {
            st.push(i + 1);

            while (pattern[i] == 'I' && !st.empty()) {
                ans.push_back('0' + st.top());
                st.pop();
            }

            while (i == pattern.size() && !st.empty()) {
                ans.push_back('0' + st.top());
                st.pop();
            }


        }
        return ans;


    }
    string smallestNumber(string pattern) {
        //return solution1(pattern);
        return solution2(pattern);
        
    }
};
