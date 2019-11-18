class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        for (int i = 0; i < n / 2; i++) {
            if (s[i] != s[n-i-1]) {
                return false;
            }
        }
        return true;
    }
    string longestPalindrome(string s) {
        if (s.size() < 2) {
            return s;
        }
        string result;
        int maxLength = 0;
        for (int i = 0; i < s.size() - maxLength; i++) {
            for (int j = s.size() - 1; j >= i + maxLength; j--) {
                if (s[i] != s[j]) {
                    continue;
                }
                string str = s.substr(i, j - i + 1);
                if (isPalindrome(str) && str.size() > maxLength) {
                    maxLength = str.size();
                    result = str;
                }
            }
        }
        return result;
    }
};