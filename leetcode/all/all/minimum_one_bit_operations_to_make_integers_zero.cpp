// Gray code always has least # of bit changes
// Treat n as Gray code and convert to decimal
// n = 3 -> 0000 ^ 0011 = 0011 -> result = 3
// n = 1 -> 0011 ^ 0001 = 0010 -> result = 2
// n = 0 -> result = 2

// n = 6 -> 0000 ^ 0110 = 0110 -> result = 6
// n = 3 -> 0110 ^ 0011 = 0101 -> result = 5
// n = 1 -> 0101 ^ 0001 = 0100 -> result = 4
// n = 0 -> result = 4

// Time: O(log n)
// Space: O(1)

class Solution {
public:
    int minimumOneBitOperations(int n) {
        int result = 0;
        
        while (n > 0) {
            result ^= n;
            n = n >> 1;
        }
        
        return result;
    }
};
