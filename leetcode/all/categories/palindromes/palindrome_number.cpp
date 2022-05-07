/*
    Given an int x, return true if x is palindrome int
    Ex. x = 121 -> true, x = -121 -> false, x = 10 -> false

    Convert to string -> optimize: revert half of the number

    Time: O(log n)
    Space: O(1)
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        int reverse = 0;
        while (x > reverse) {
            reverse = reverse * 10 + x % 10;
            x /= 10;
        }
        // even number of digits || odd number of digits
        return x == reverse || x == reverse / 10;
    }
};
