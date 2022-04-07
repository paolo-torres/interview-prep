// Stack, pop if last char in result = curr char, else push

// Time: O(n)
// Space: O(n - d) -> length of string - # of duplicates

class Solution {
public:
    string removeDuplicates(string s) {
        string result = "";
        
        for (int i = 0; i < s.size(); i++) {
            if (!result.empty() && result.back() == s[i]) {
                result.pop_back();
            } else {
                result.push_back(s[i]);
            }
        }
        
        return result;
    }
};
