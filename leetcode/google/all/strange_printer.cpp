/*
    There is a strange printer with the following 2 properties:
        Printer can only print a sequence of the same char each time
        At each turn, can print new chars starting from & ending at
            any place & will cover the original existing chars
    Given a string, return min # of turns printer needed to print it
    Ex. s = "aaabbb" -> 2, "aaa", "bbb"

    Partition string into substrings, get turns of each, store min #
    Min # will be some index 'k' that minimizes turns, find this 'k'

    Time: O(n^3)
    Space: O(n)
*/

class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        dp = vector<vector<int>>(n, vector<int>(n));
        return dfs(s, 0, s.size() - 1);
    }
private:
    vector<vector<int>> dp;
    
    int dfs(string& s, int i, int j) {
        if (i == j) {
            return 1;
        }
        if (dp[i][j] != 0) {
            return dp[i][j];
        }
        
        int minTurns = INT_MAX;
        
        for (int k = i; k < j; k++) {
            minTurns = min(minTurns, dfs(s, i, k) + dfs(s, k + 1, j));
        }
        
        dp[i][j] = (s[i] == s[j]) ? minTurns - 1 : minTurns;
        return dp[i][j];
    }
};
