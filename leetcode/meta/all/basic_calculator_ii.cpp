// prevNum is like a "stack", if mul/div update stack, if add/sub update result

// Time: O(n)
// Space: O(1)

class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        
        int prevNum = 0;
        int currNum = 0;
        
        char sign = '+';
        int result = 0;
        
        for (int i = 0; i < n; i++) {
            char currChar = s[i];
            
            if (isdigit(currChar)) {
                currNum = (currNum * 10) + (currChar - '0');
            }
            
            if (!isdigit(currChar) && !isspace(currChar) || i == n - 1) {
                if (sign == '+' || sign == '-') {
                    result += prevNum;
                    if (sign == '+') {
                        prevNum = currNum;
                    } else {
                        prevNum = -currNum;
                    }
                } else if (sign == '*') {
                    prevNum *= currNum;
                } else {
                    prevNum /= currNum;
                }
                
                sign = currChar;
                currNum = 0;
            }
        }
        
        result += prevNum;
        return result;
    }
};
