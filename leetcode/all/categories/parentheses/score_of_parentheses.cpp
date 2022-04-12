// Count depths, every match adds "()" exponent depth

// Time: O(n)
// Space: O(1)

class Solution {
public:
    int scoreOfParentheses(string s) {
        int depth = 0;
        int result = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                depth++;
            } else {
                depth--;
            }
            
            if (s[i] == ')' && s[i - 1] == '(') {
                // when "()" pair, times 2 for every depth
                result += pow(2, depth);
            }
        }
        
        return result;
    }
};
