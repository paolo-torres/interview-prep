// Incr open, decr close, result is max opens

// Time: O(n)
// Space: O(1)

class Solution {
public:
    int maxDepth(string s) {
        int open = 0;
        int result = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                open++;
                result = max(result, open);
            } else if (s[i] == ')') {
                open--;
            }
        }
        
        return result;
    }
};
