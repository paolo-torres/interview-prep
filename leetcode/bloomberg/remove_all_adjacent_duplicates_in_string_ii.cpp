// Maintain char counts, if count = k remove

// Time: O(n)
// Space: O(n)

class Solution {
public:
    string removeDuplicates(string s, int k) {
        // pair of {char -> frequency}
        vector<pair<char, int>> stk;
        
        for (int i = 0; i < s.size(); i++) {
            if (stk.empty() || stk.back().first != s[i]) {
                stk.push_back({s[i], 1});
                continue;
            }
            
            // increase frequency
            stk.back().second++;
            // if reach k duplicate chars, then remove
            if (stk.back().second == k) {
                stk.pop_back();
            }
        }
        
        string result;
        for (int i = 0; i < stk.size(); i++) {
            result.append(stk[i].second, stk[i].first);
        }
        return result;
    }
};
