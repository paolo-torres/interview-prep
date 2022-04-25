/*
    Start from 1, remove any int that contains 9 (9, 19, 29, ...)
    Given n, return nth (1-indexed) integer in the new sequence
    Ex. n = 9 -> 10, n = 10 -> 11

    Removing any int w/ 9, base-9 numbers, find nth base-9 number

    1, 2, 3, 4, 5, 6, 7, 8,
    10, 11, 12, 13, 14, 15, 16, 17, 18,
    20, 21, 22, 23, 24, 25, 26, 27, 28,
    ...
    80, 81, 82, 83, 84, 85, 86, 87, 88,
    100, 101, 102, ...

    Time: O(log n)
    Space: O(1)
*/

class Solution {
public:
    int newInteger(int n) {
        long base = 1;
        long result = 0;
        while (n != 0) {
            result = result + (n % 9) * base;
            n /= 9;
            base *= 10;
        }
        return (int) result;
    }
};
