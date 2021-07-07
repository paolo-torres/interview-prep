// Time: O(n^2)
// Space: O(1)

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        
        if (n == 1) {
            return 1;
        }
        
        int result = 0;
        
        for (int i = 0; i < n; i++) {
            expandPalindrome(s, i, i, result);
            expandPalindrome(s, i, i + 1, result);
        }
        
        return result;
    }
private:
    void expandPalindrome(string s, int i, int j, int& result) {
        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            result++;
            i--;
            j++;
        }
    }
};
