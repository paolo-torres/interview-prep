// Remove all invalid ")", remove all rightmost "("

// Time: O(n)
// Space: O(n)

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string str = "";
        int openSeen = 0;
        int balance = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                openSeen++;
                balance++;
            } else if (s[i] == ')') {
                if (balance == 0) {
                    continue;
                }
                balance--;
            }
            str += s[i];
        }
        
        string result = "";
        int openKeep = openSeen - balance;
        
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '(') {
                openKeep--;
                if (openKeep < 0) {
                    continue;
                }
            }
            result += str[i];
        }
        
        return result;
    }
};
