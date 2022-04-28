/*
    Given 2 strings, return true if 1 can become the other after some # of shifts
    Ex. s = "abcde" goal = "cdeab" -> true, s = "abcde" goal = "abced" -> false

    Append s to itself, then try to find goal in s

    Time: O(n^2)
    Space: O(n)
*/

class Solution {
public:
    bool rotateString(string s, string goal) {
        return s.size() == goal.size() && (s + s).find(goal) != string::npos;
    }
};
