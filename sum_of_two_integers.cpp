class Solution {
public:
    int getSum(int a, int b) {
        int sum = 0;
        while (b != 0) {
            sum = a ^ b;
            b = (unsigned int)(a & b) << 1;
            a = sum;
        }
        return sum;
    }
};
