class Solution {
public:
    int minAddToMakeValid(string S) {
        if (S.empty()) {
            return 0;
        }
        stack<char> open;
        int result = 0;
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == '(') {
                open.push(S[i]);
                result++;
            } else {
                if (open.empty()) {
                    result++;
                } else {
                    open.pop();
                    result--;
                }
            }
        }
        return result;
    }
};
