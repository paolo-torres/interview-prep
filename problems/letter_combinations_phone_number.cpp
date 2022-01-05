class Solution {
private:
    void findCombos(string digits, unordered_map<char, string>& m, int index, string str, vector<string>& result) {
        if (index == digits.size()) {
            result.push_back(str);
            return;
        }
        auto it = m.find(digits[index]);
        for (int i = 0; i < it->second.size(); i++) {
            str.push_back(it->second[i]);
            findCombos(digits, m, index + 1, str, result);
            str.pop_back();
        }
    }
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
        findCombos(digits, m, 0, "", result);
        return result;
    }
};
