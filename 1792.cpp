class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int all_pass = 0;
        auto cmp = [](pair<int, int> left, pair<int, int> right) {
		    return ( 
                ((double)left.first + 1) / ((double)left.second + 1) - 
                    (double)left.first/left.second
                ) 
                < 
                (
                    ((double)right.first + 1) / ((double)right.second + 1) - 
                    (double)right.first/right.second
                ) ;
        };
        std::priority_queue<pair<int, int>, std::vector<pair<int, int>>, decltype(cmp)> hp;
        for (auto& item : classes) {
            int pass = item[0], total = item[1];
            if (pass == total) {
                all_pass++;
                continue;
            }
            hp.push(make_pair(pass, total));
        }

        if (hp.empty()) return 1;
        while (extraStudents--) {
            auto p = hp.top(); hp.pop();
            int pass = p.first + 1;
            int total = p.second + 1;
            hp.push(make_pair(pass, total));
        }

        double sum = 0;
        int count = 0;
        int size = hp.size();
        while (hp.empty() == false) {
            auto p = hp.top(); hp.pop();
            double pass = p.first;
            double total = p.second;
            sum += pass/total;
            count++;
        }
        sum += all_pass;
        count += all_pass;
        return sum / count;
    }
};
