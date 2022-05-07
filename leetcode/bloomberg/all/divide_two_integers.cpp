/*
    Given ints dividend & divisor, divide w/o *, /, %
    Ex. dividend = 10, divisor = 3 -> 3

    Add powers of 2 w/ bit shifting
    Work w/ -'ve bc more -'ve than +'ve to avoid overflow

    Time: O(log n)
    Space: O(1)
*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        // overflow
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        
        // convert both numbers to -'ve & count -'ves
        int negatives = 2;
        if (dividend > 0) {
            negatives--;
            dividend = -dividend;
        }
        if (divisor > 0) {
            negatives--;
            divisor = -divisor;
        }
        
        // find largest double of divisor
        int highestDouble = divisor;
        int highestPowerOfTwo = -1;
        while (highestDouble >= (INT_MIN / 2)
            && dividend <= highestDouble + highestDouble) {
            highestPowerOfTwo += highestPowerOfTwo;
            highestDouble += highestDouble;
        }
        
        // work out which powers of two fit in
        int quotient = 0;
        while (dividend <= divisor) {
            if (dividend <= highestDouble) {
                quotient += highestPowerOfTwo;
                dividend -= highestDouble;
            }
            highestPowerOfTwo >>= 1;
            highestDouble >>= 1;
        }
        
        // if there was originally 1 -'ve, remains -'ve
        if (negatives != 1) {
            return -quotient;
        }
        return quotient;
    }
};
