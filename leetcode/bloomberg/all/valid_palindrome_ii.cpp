/*
    Given string, return true if can be palindrome after deleting at most 1 char
    Ex. s = "abca" -> true delete 'c', s = "abc" -> false

    2 pointers, outside in until mismatch, try both ranges

    Time: O(n)
    Space: O(1)
*/

class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        
        while (i < j) {
            if (s[i] != s[j]) {
                return isPalindrome(s, i + 1, j) || isPalindrome(s, i, j - 1);
            }
            i++;
            j--;
        }
        
        return true;
    }
private:
    bool isPalindrome(string s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
