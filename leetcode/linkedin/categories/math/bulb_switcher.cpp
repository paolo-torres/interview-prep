/*
    n bulbs off, 1st turn on all, then turn off every 2nd
    Then toggle every 3rd -> ith round toggle every i bulb
    Return # of bulbs that are on after n rounds

    Every ith distance switch bulb to opposite state
    1 to n, every 2nd bulb: 2, 4, 6, 8, all even numbers
    every 3rd bulb: 3, 6, 9, 12, ..., multiples of 3
    Bulb only has 2 diff states, on or off:
    Odd switching operations will result in bulb on
    Even switching operations will result in bulb off

    Goal: search for odd operation numbers
        Primes: 1 and itself as factors, even operation
        Non-primes: diff pair of factors
            Ex. 12: (1, 12), (3, 4), (2, 6)
        Perfect squares special case
            Ex. 9: (1, 9), (3, 3) odd operation numbers
        To get amount of squares < n -> sqrt(n)

    Time: O(1)
    Space: O(1)
*/

class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};
