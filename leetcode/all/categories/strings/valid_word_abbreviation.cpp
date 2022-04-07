// 2 pointers, iterate i for the num of j, compare chars

// Time: O(n)
// Space: O(1)

class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0;
        int j = 0;
        
        while (i < word.size() && j < abbr.size()) {
            if (word[i] == abbr[j]) {
                i++;
                j++;
                continue;
            }
            
            if (abbr[j] == '0' || isalpha(abbr[j])) {
                return false;
            }
            
            int start = j;
            while (j < abbr.size() && isdigit(abbr[j])) {
                j++;
            }
            int num = stoi(abbr.substr(start, j - start));
            i += num;
        }
        
        if (i == word.size() && j == abbr.size()) {
            return true;
        }
        return false;
    }
};
