class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        if (arr.size() <= 1) return arr.size();
        int max_index = 0;
        int chunk = 0;
        for (int i = 0; i < arr.size(); i++) {
            max_index = max(max_index, arr[i]);
            if (i == max_index) {
                chunk++;
                max_index = i + 1;
            }
        }
        return chunk;
        
    }
};
