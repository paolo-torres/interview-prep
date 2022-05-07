/*
    Find longest common prefix string amongst array of strings
    Ex. strs = ["flower","flow","flight"]

    For each char in 1st string, compare w/ every other string

    Time: O(m x n) -> m = # of strings, n = length of longest string
    Space: O(1)
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        for (int i = 0; i < strs[0].size(); i++) {
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (i == strs[j].size() || strs[j][i] != c) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};
