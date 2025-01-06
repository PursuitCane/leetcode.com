class Solution {
public:
    string tle1(string& s, vector<vector<int>>& shifts) {
        for (auto vec : shifts) {
            int st = vec[0];
            int end = vec[1];
            int dir = vec[2];
            if (dir) {
                for (int i = st; i <= end; i++) {
                    if (s[i] == 'z')
                        s[i] = 'a';
                    else
                        s[i] = s[i] + 1;
                }
            } else {
                for (int i = st; i <= end; i++) {
                    if (s[i] == 'a')
                        s[i] = 'z';
                    else
                        s[i] = s[i] - 1;
                }
            }
        }
        return s;
    }
    string tle2(string& s, vector<vector<int>>& shifts) {
        vector<int> ps(s.size());
        for (int i = 0; i < s.size(); i++) {
            for (auto vec : shifts) {
                int st = vec[0];
                int end = vec[1];
                int dir = vec[2];
                if (i < st | i > end)
                    continue;
                if (dir)
                    ps[i]++;
                else
                    ps[i]--;
            }
        }
        for (int i = 0; i < s.size(); i++) {
            s[i] = 'a' + ((s[i] - 'a'+ ps[i]) % 26 + 26) % 26;
        }
        return s;
    }

    string presum(string& s, vector<vector<int>>& shifts) {
         vector<int> arr(s.size() + 1);
        for (auto vec : shifts) {
            int st = vec[0];
            int end = vec[1];
            int dir = vec[2];
            if (dir) {
                arr[st]++;
                arr[end + 1]--;
            } else {
                arr[st]--;
                arr[end + 1]++;
            }
        }
        int ps = 0;
        for (int i = 0; i < s.size(); i++) {
            ps += arr[i];
            s[i] = 'a' + ((s[i] - 'a'+ ps) % 26 + 26) % 26;
        }
        return s;
    }
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        //return tle1(s, shifts);
        //return tle2(s, shifts);
        return presum(s, shifts);
        
    }
};
