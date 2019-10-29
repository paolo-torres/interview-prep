class Solution {
public:
    bool isValid(string s) {
        if (s.empty()) {
            return true;
        }
        stack <char> myStack;
        for (auto it = s.begin(); it != s.end(); ++it) {
            if (*it == '(' || *it == '{' || *it == '[') {
                myStack.push(*it);
            } else if (myStack.empty()
                && (*it == ')' || *it == '}' || *it == ']')) {
                return false;
            } else {
                if (myStack.top() == '(' && *it != ')'
                    || myStack.top() == '{' && *it != '}'
                    || myStack.top() == '[' && *it != ']') {
                    return false;
                }
                myStack.pop();
            }
        }
        if (!myStack.empty()) {
            return false;
        }
        return true;
    }
};
