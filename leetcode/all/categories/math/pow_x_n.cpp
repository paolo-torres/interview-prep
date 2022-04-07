// // Divide-and-conquer, even x^n = A * A, odd x^n = A * A * x

// // Time: O(log n)
// // Space: O(log n)

// class Solution {
// public:
//     double myPow(double x, int n) {
//         long exponent = abs(n);
//         double result = helper(x, exponent);
//         if (n >= 0) {
//             return result;
//         }
//         return 1.0 / result;
//     }
// private:
//     double helper(double x, long n) {
//         if (x == 0.0) {
//             return 0;
//         }
//         if (n == 0) {
//             return 1.0;
//         }
        
//         double result = helper(x * x, n / 2);
//         if (n % 2 == 0) {
//             return result;
//         }
//         return result * x;
//     }
// };

// Time: O(log n)
// Space: O(1)

class Solution {
public:
    double myPow(double x, int n) {
        long exponent = abs(n);
        double curr = x;
        double result = 1.0;
        
        for (long i = exponent; i > 0; i /= 2) {
            if (i % 2 == 1) {
                result *= curr;
            }
            curr *= curr;
        }
        
        if (n < 0) {
            return 1.0 / result;
        }
        return result;
    }
};
