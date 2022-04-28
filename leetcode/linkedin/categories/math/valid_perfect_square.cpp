/*
    Given int, return true if perfect square
    Ex. num = 16 -> true, num = 14 -> false

    Binary search to find an x, where x * x = num

    Time: O(log n)
    Space: O(1)
*/

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 2) {
            return true;
        }
        
        long low = 2;
        long high = num / 2;
        
        while (low <= high) {
            long x = low + (high - low) / 2;
            long guess = x * x;
            if (guess < num) {
                low = x + 1;
            } else if (guess > num) {
                high = x - 1;
            } else {
                return true;
            }
        }
        
        return false;
    }
};
