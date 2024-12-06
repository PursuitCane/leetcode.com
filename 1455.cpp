class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int index = 1;
        int j = 0, size = searchWord.size();
        bool mark = true;
        for (int i = 0; i < sentence.size(); i++) {
            if (sentence[i] == ' ') {
                index++;
                mark = true;
                j = 0;
                continue;
            }
            if (mark && sentence[i] == searchWord[j]) j++;
            else { 
                j = 0;
                mark = false;
            }
            if (j == size) return index;
        }
        return -1;
        
    }
};
