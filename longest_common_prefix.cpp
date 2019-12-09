class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string empty;
        if (strs.empty()) {
            return empty;
        }
        string result = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            while (result != strs[i]) {
                if (result.size() < strs[i].size()) {
                    strs[i] = strs[i].substr(0, result.size());
                } else {
                    result = result.substr(0, result.size() - 1);
                }
                if (result.empty()) {
                    return empty;
                }
            }
        }
        return result;
    }
};
