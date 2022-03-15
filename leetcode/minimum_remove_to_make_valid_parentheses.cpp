class Solution {
public:
    string minRemoveToMakeValid(string s) {
        if (s.empty()) {
            return s;
        }
        stack<int> open;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                open.push(i);
            } else if (s[i] == ')') {
                if (!open.empty()) {
                    open.pop();
                } else {
                    s[i] = '*';
                }
            }
        }
        while (!open.empty()) {
            s[open.top()] = '*';
            open.pop();
        }
        s.erase(remove(s.begin(), s.end(), '*'), s.end());
        return s;
    }
};
