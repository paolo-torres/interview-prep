// If open push, if close and nonempty pop

// Time: O(n)
// Space: O(1)

class Solution {
public:
    int minAddToMakeValid(string s) {
        int stack = 0;
        int mismatch = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stack++;
            } else if (s[i] == ')' && stack > 0) {
                stack--;
            } else {
                mismatch++;
            }
        }
        
        return stack + mismatch;
    }
};
