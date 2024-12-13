class Solution {
public:
    long long findScore(vector<int>& nums) {
        vector<pair<int, int>> vec;
        for (int i = 0; i < nums.size(); i++) {
            vec.push_back(make_pair(nums[i], i));
        }

        sort(vec.begin(), vec.end(), 
            [](pair<int, int> l, pair<int, int> r) { 
                if (l.first == r.first) {
                    return l.second < r.second;
                }
                return l.first < r.first;
            });

        long long score = 0;
        vector<bool> mark(vec.size());
        for (auto pair : vec) {
            int num = pair.first;
            int index = pair.second;
            if (mark[index] == false) {
                score += num;
                if (index > 0) mark[index - 1] = true;
                if (index < vec.size() - 1) mark[index + 1] = true;
            }
        }
        return score;
    }
};
