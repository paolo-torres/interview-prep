/*
    The Collatz Conjecture says if you take a positive integer N and
    repeatedly set either N = N / 2 (if it's even) or N = 3N + 1
    (if it's odd), N will eventually be 1. Given N, how many steps
    does it take to reach 1?
    Ex. 5 -> 16 -> 8 -> 4 -> 2 -> 1 (5 steps)
    
    DFS + memo, hash map {n -> # of steps}, add base case of {1 -> 0}

    Time: T(n) = 1 n <= 1, T(n) = T(n/2) + 1 even, T(n) = T(3n + 1) + 1 odd
    Space: O(n)
*/

#include <stdio.h>

#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    Solution() {
        memo[1] = 0;
    }

    int collatzConjecture(int n) {
        if (memo.find(n) != memo.end()) {
            return memo[n];
        }

        int result = 0;
        if (n % 2 == 0) {
            result = 1 + collatzConjecture(n / 2);
        } else {
            result = 1 + collatzConjecture(3 * n + 1);
        }

        memo[n] = result;
        return result;
    }
private:
    // {n -> number of steps to become 1}
    unordered_map<int, int> memo;
};

int main() {
    int n = 5;
    Solution* obj = new Solution();
    cout << obj->collatzConjecture(n) << endl;

    return 0;
}
