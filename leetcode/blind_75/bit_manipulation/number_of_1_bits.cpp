// Time: O(1)
// Space: O(1)

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int bit = 0;
        int result = 0;
        
        while (n != 0) {
            bit = n & 1;
            if (bit == 1) {
                result++;
            }
            n = n >> 1;
        }
        
        return result;
    }
};
