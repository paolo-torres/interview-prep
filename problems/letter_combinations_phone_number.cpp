// Time: O(n x 4^n)
// Space: O(n x 4^n)

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) {
            return result;
        }
        unordered_map<char, string> m = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        string curr;
        findCombos(digits, 0, m, curr, result);
        return result;
    }
private:
    void findCombos(string digits, int index, unordered_map<char, string>& m, string& curr, vector<string>& result) {
        if (index == digits.size()) {
            result.push_back(curr);
            return;
        }
        string str = m[digits[index]];
        for (int i = 0; i < str.size(); i++) {
            curr.push_back(str[i]);
            findCombos(digits, index + 1, m, curr, result);
            curr.pop_back();
        }
    }
};
