class Solution {
private:
    map<int, string> m = {
        {2, "abc"},
        {3, "def"},
        {4, "ghi"},
        {5, "jkl"},
        {6, "mno"},
        {7, "pqrs"},
        {8, "tuv"},
        {9, "wxyz"}
    };
    vector<string> result;
    void makeCombos(vector<string>& nums, int pos, string& str, int size) {
        if (size == str.size()) {
            result.push_back(str);
            return;
        }
        for (auto it = nums[pos].begin(); it != nums[pos].end(); ++it) {
            str.push_back(*it);
            makeCombos(nums, pos + 1, str, size);
            str.pop_back();
        }
    }
    
public:
    vector<string> letterCombinations(string digits) {
        vector<string> nums;
        if (digits.empty()) {
            return nums;
        }
        for (int i = 0; i < digits.size(); i++) {
            auto it = m.find(digits[i] - '0');
            nums.push_back(it->second);
        }
        string str;
        makeCombos(nums, 0, str, digits.size());
        return result;
    }
};
