class Solution {
public:
    int to_number(vector<vector<int>>& board) {
        int ret = 0;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                ret = ret * 10 + board[i][j];
            }
        }
        return ret;
    }

    int find_zero(int number) {
        int ret = 0;
        while (number % 10 != 0) {
            ret++;
            number /= 10;
        }
        return ret;
    }

    int do_swap(int number, int index1, int index2) {
        //printf("number %d index1 %d index2 %d\n", number, index1, index2);
        vector<int> vec;
        while (number) {
            vec.push_back(number % 10);
            number /= 10;
        }
        if (vec.size() != 6) vec.push_back(0);
        swap(vec[index1], vec[index2]);
        int ret = 0;
        for (int i = 0; i < vec.size(); i++) {
            ret = ret*10 + vec[vec.size() -i -1];
        }
        return ret;
    }

    int slidingPuzzle(vector<vector<int>>& board) {
        int goal = 123450;
        unordered_map<int, int> mp;
        queue<int> que;
        que.push(to_number(board));
        if (que.front() == goal) return 0;
        mp[que.front()] = 0;
        vector<vector<int>> dir;
        dir.push_back({1, 3}); // i = 1 j = 2
        dir.push_back({0, 2, 4});
        dir.push_back({1, 5});
        dir.push_back({0, 4});
        dir.push_back({1, 3, 5});
        dir.push_back({2, 4});
        while (que.empty() == false) {
            int curr_number = que.front(); que.pop();
            int zero_index = find_zero(curr_number);
            //printf("curr_number %d zero_index %d\n", curr_number, zero_index);
            int step = mp[curr_number];
            for (int i = 0; i < dir[zero_index].size(); i++) {
                int swap_number = do_swap(curr_number, zero_index, dir[zero_index][i]);           
                //printf("swap_number %d step %d\n", swap_number, step);
                if (swap_number == goal) {
                    return step + 1;
                }
                if (mp.find(swap_number) == mp.end()) {
                    
                    que.push(swap_number);
                    mp[swap_number] = step + 1;
                }
            }
        }
        return -1;
    }
};
