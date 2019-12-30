class Solution {
private:
    void findCombos(string digits, string temp, vector<string>& result, unordered_map<int, string>& m, int index) {
        if (index == digits.size()) {
            result.push_back(temp);
            return;
        }
        auto it = m.find(digits[index] - '0');
        for (int i = 0; i < it->second.size(); i++) {
            temp.push_back(it->second[i]);
            findCombos(digits, temp, result, m, index + 1);
            temp.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) {
            return result;
        }
        unordered_map<int, string> m;
        m.insert({2, "abc"});
        m.insert({3, "def"});
        m.insert({4, "ghi"});
        m.insert({5, "jkl"});
        m.insert({6, "mno"});
        m.insert({7, "pqrs"});
        m.insert({8, "tuv"});
        m.insert({9, "wxyz"});
        string temp;
        findCombos(digits, temp, result, m, 0);
        return result;
    }
};
