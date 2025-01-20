class Solution {
public:
    vector<int> solution1(vector<int>& A, vector<int>& B) {
        unordered_set<int> s;
        vector<int> C(A.size());
        for (int i = 0; i < A.size(); i++) {
            s.insert(A[i]);
            for (int j = 0; j <= i; j++) {
                if (s.count(B[j])) C[i]++;
            }
        }
        return C;
    }

    vector<int> solution2(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> m;
        vector<int> C(A.size());
        for (int i = 0; i < A.size(); i++) {
            m[A[i]]++;
            m[B[i]]++;
            if (i != 0) C[i] = C[i-1];
            if (m[A[i]] == 2) C[i]++;
            if (A[i] == B[i]) continue;
            if (m[B[i]] == 2) C[i]++;
        }
        return C;
    }
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        //return solution1(A, B);
        return solution2(A, B);
        
        
    }
};
