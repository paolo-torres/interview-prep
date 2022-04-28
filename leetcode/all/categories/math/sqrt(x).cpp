/*
    Given non-negative int s, compute & return sqrt of x
    Ex. x = 4 -> 2, x = 8 -> 2

    Binary search [2, x/2], guess mid, then adjust if too low/high

    Time: O(log n)
    Space: O(1)
*/

class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) {
            return x;
        }
        
        int low = 2;
        int high = x / 2;
        
        while (low <= high) {
            int guess = low + (high - low) / 2.0;
            long num = (long) guess * guess;
            
            if (num < x) {
                low = guess + 1;
            } else if (num > x) {
                high = guess - 1;
            } else {
                return guess;
            }
        }
        
        // when exit while loop, left > right, but want smaller
        return high;
    }
};
