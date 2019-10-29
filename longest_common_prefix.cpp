class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string empty = "";
        if (strs.empty()) {
            return empty;
        }
        string prefix = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            while (prefix != strs[i] && prefix != "") {
                if (strs[i].size() > prefix.size()) {
                    strs[i] = strs[i].substr(0, prefix.size());
                } else {
                    prefix = prefix.substr(0, prefix.size() - 1);
                }
            }
            if (prefix == "") {
                return empty;
            }
        }
        return prefix;
    }
};
