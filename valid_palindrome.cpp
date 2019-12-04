class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() < 2) {
            return true;
        }
        for (int i = 0; i < s.size(); i++) {
            if (isalpha(s[i])) {
                s[i] = tolower(s[i]);
            } else if (ispunct(s[i]) || isspace(s[i])) {
                s.erase(i, 1);
                i--;
            }
        }
        int n = s.size();
        for (int i = 0; i < n / 2; i++) {
            if (s[i] != s[n-i-1]) {
                return false;
            }
        }
        return true;
    }
};
