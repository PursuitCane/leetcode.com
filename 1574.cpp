class Solution {
public:
    int upper_bound(int num, int r, vector<int>& arr) {
        if (arr[0] > num) return -1;
        int l = 0;
        while (l < r) {
            int mid = ((l + r) >> 1) + ((l + r) & 1);
            if (arr[mid] > num) r = mid -1;
            else l = mid;
        }
        return l;
    }
    int solution1(vector<int>& arr) { // o nlogn
        int size = arr.size();
        int prefix_index = 0;
        for (int i = 1; i < size; i++) {
            if (arr[i-1] <= arr[i]) prefix_index++;
            else break;
        }
        int suffix_index = size - 1;
        for (int i = size - 2; i >= 0; i--) {
            if (arr[i] <= arr[i+1]) suffix_index--;
            else break;
        }
        if (prefix_index >= suffix_index) return 0;
        //printf("prefix_index %d suffix_index %d\n", prefix_index, suffix_index);
        int ans = max(prefix_index + 1, size - suffix_index);
        for (int i = suffix_index; i < size; i++) {
            int index = upper_bound(arr[i], prefix_index, arr);
            //printf("arr[i] %d index %d\n", arr[i], index);
            ans = max(ans, size - i + index + 1);
        }
        return size - ans;
        
    }
    int solution2(vector<int>& arr) { // two pointer o n
        int suffix_prefix = arr.size() - 1;
        for (int i = arr.size()-2; i >= 0; i--) {
            if (arr[i] <= arr[i+1]) suffix_prefix--;
            else break;
        }
        int ans = suffix_prefix;
        if (ans == 0) return 0;
        int i = 0, j = suffix_prefix, size = arr.size();
        for (int i = 0; i < suffix_prefix; i++) {
            while (j < size && arr[i] > arr[j]) {
                j++;
            }
            if (j >= size) ans = min(ans, size - i);
            ans = min(ans, j - i -1);
            if (arr[i] > arr[i+1]) break;
        }
        return ans;
    }
    int findLengthOfShortestSubarray(vector<int>& arr) {
        //return solution1(arr);
        return solution2(arr); 
    }

};
