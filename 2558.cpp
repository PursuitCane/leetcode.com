class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        std::priority_queue<long long, std::vector<long long>> hp;
        for (auto item : gifts) {
            hp.push(item);
        }

        while (k--) {
            long long item = hp.top(); hp.pop();
            item = sqrt(item);
            hp.push(item);
        }

        long long ans = 0;
        while (!hp.empty()) {
            ans += hp.top(); hp.pop();
        }
        return ans;
        
    }
};
