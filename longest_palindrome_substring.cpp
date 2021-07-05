// Time: O(n^2)
// Space: O(1)

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        
        if (n == 1) {
            return s;
        }
        
        int maxStart = 0;
        int maxLength = 1;
        
        for (int i = 0; i < n - 1; i++) {
            expandPalindrome(s, i, i, maxStart, maxLength);
            expandPalindrome(s, i, i + 1, maxStart, maxLength);
        }
        
        return s.substr(maxStart, maxLength);
    }
private:
    void expandPalindrome(string s, int i, int j, int& maxStart, int& maxLength) {
        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            i--;
            j++;
        }
        if (j - i - 1 > maxLength) {
            maxStart = i + 1;
            maxLength = j - i - 1;
        }
    }
};
