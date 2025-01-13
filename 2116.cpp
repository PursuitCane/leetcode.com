class Solution {
public:
    bool canBeValid(string s, string locked) {
        if (s.size() & 1) return false;
        stack<int> st_lock;
        stack<int> unlock;
        for (int i = 0; i < s.size(); i++) {
            if (locked[i] == '0') {
                unlock.push(i);
                continue;
            }
            if (s[i] == '(') {
                st_lock.push(i);
            }
            if (s[i] == ')') {
                if (st_lock.empty() && unlock.empty()) return false;
                if (st_lock.empty() == false) st_lock.pop();
                else unlock.pop();
            }
        }
        while (!st_lock.empty()) {
            if (unlock.empty()) return false;
            if (st_lock.top() < unlock.top()) {
                st_lock.pop();
                unlock.pop();
                continue;
            }
            return false;
        }
        return true;
    }
};
