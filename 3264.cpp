class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        auto cmp = [](pair<int, int> left, pair<int, int> right) {
                if (left.first == right.first) return left.second > right.second;
		        return left.first > right.first;
        };
        std::priority_queue<pair<int, int>, std::vector<pair<int, int>>, decltype(cmp)> hp;
        
        for (int i = 0; i < nums.size(); i++) {
            hp.push(make_pair(nums[i], i));
        }

        while (k--) {
            auto p = hp.top(); hp.pop();
            nums[p.second] *= multiplier;
            hp.push(make_pair(nums[p.second], p.second));
            //printf("p.second %d value %d\n", p.second, nums[p.second]);
        }

        return nums;
    }
};
