class Solution {
public:
    bool isValid(string s) {
        if (s.empty()) {
            return true;
        }
        stack<char> open;
        for (int i = 0; i < s.size(); i++) {
            if ((s[i] == ')' || s[i] == '}' || s[i] == ']') && open.empty()) {
                return false;
            } else if (s[i] == ')' && open.top() != '('
                || s[i] == '}' && open.top() != '{'
                || s[i] == ']' && open.top() != '[') {
                return false;
            } else if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                open.push(s[i]);
            } else {
                open.pop();
            }
        }
        if (open.empty()) {
            return true;
        } else {
            return false;
        }
    }
};
