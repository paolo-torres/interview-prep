/*
    Given a string, sources & targets, perform find and replace, & return the resulting string
    Ex. s = "abcd", indices = [0,2], sources = ["a","cd"], targets = ["eee","ffff"] -> "eeebffff"

    Hash map {replacement index -> original string index}, perform replacements if exists

    Time: O(n^2)
    Space: O(n)
*/

class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        // hash map of replacements we need to do
        unordered_map<int, int> m;
        for (int i = 0; i < indices.size(); i++) {
            string str = s.substr(indices[i], sources[i].size());
            if (str == sources[i]) {
                m[indices[i]] = i;
            }
        }
        
        string result = "";
        
        int i = 0;
        while (i < s.size()) {
            if (m.find(i) != m.end()) {
                // mapping exists, perform the replacement
                result += targets[m[i]];
                i += sources[m[i]].size();
            } else {
                // mapping does not exist, use original
                result += s[i];
                i++;
            }
        }
        
        return result;
    }
};
