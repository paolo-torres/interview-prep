// Time: O(2^n)
// Space: O(n)

class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> result;
        findPermutations(s, 0, result);
        return result;
    }
private:
    void findPermutations(string s, int i, vector<string>& result) {
        if (i == s.size()) {
            result.push_back(s);
            return;
        }
        
        findPermutations(s, i + 1, result);
        
        if (isalpha(s[i])) {
            s[i] = toggle(s[i]);
            findPermutations(s, i + 1, result);
        }
    }
    char toggle(char letter) {
        return isupper(letter) ? tolower(letter) : toupper(letter);
    }
};
