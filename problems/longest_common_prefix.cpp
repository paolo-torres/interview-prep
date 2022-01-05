class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result;
        if (strs.empty()) {
            return result;
        }
        result = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            while (!result.empty() && result != strs[i]) {
                if (result.size() < strs[i].size()) {
                    strs[i] = strs[i].substr(0, result.size());
                } else {
                    result = result.substr(0, result.size() - 1);
                }
            }
        }
        return result;
    }
};
