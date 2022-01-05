class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor) {
            return 1;
        } else if (dividend == 0 || divisor == INT_MIN) {
            return 0;
        } else if (divisor == 1) {
            return dividend;
        } else if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        } else if (dividend == -divisor) {
            return -1;
        }
        bool isNegative = false;
        if (dividend > 0 && divisor < 0
           || dividend < 0 && divisor > 0) {
            isNegative = true;
        }
        bool isMin = false;
        if (dividend == INT_MIN) {
            isMin = true;
            dividend++;
        }
        dividend = abs(dividend);
        divisor = abs(divisor);
        if (dividend < divisor) {
            return 0;
        }
        int result = 0;
        while (dividend >= divisor) {
            int temp = divisor;
            int n = 1;
            while (temp << 1 > 0 && temp << 1 <= dividend) {
                temp <<= 1;
                n <<= 1;
            }
            result += n;
            dividend -= temp;
        }
        if (isMin) {
            dividend++;
            while (dividend >= divisor) {
                result++;
                dividend -= divisor;
            }
        }
        if (isNegative) {
            return -result;
        } else {
            return result;
        }
    }
};
