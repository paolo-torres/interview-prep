/*
    Given 2 strings s1 & s2 of size n & an evil string, return # of good strings
    Good: Has size n, alphabetically >= s1, <= s2, doesn't contain evil as substring
    Ex. n = 2, s1 = "aa", s2 = "da", evil = "b" -> 51, "aa","ac","ad",..."ca","cc",...

    DFS + memo + backtracking, KMP to determine whether current branch is hopeless
    KMP to check string matches as we backtrack, find longest prefix/suffix for KMP

    Time: O(m x n)
    Space: O(m x n)
*/

class Solution {
public:
    int findGoodStrings(int n, string s1, string s2, string evil) {
        vector<int> lps = getLPS(evil);
        return dfs(n, s1, s2, evil, 0, 0, true, true, lps);
    }
private:
    int mod = pow(10, 9) + 7;
    // n, evil, left, right
    int dp[501][51][2][2];
    
    int dfs(int n, string& s1, string& s2, string& evil,
            int i, int evilMatch, bool left, bool right, vector<int>& lps) {
        // contains evil as substring, not a good string
        if (evilMatch == evil.size()) {
            return 0;
        }
        // good string
        if (i == n) {
            return 1;
        }
        // we've seen this value already
        if (dp[i][evilMatch][left][right] != 0) {
            return dp[i][evilMatch][left][right];
        }
        
        char from = left ? s1[i] : 'a';
        char to = right ? s2[i] : 'z';
        
        int result = 0;
        
        for (char c = from; c <= to; c++) {
            // j is next match between curr string (end at char c) & evil string
            int j = evilMatch;
            while (j > 0 && evil[j] != c) {
                j = lps[j - 1];
            }
            if (c == evil[j]) {
                j++;
            }
            result += dfs(n, s1, s2, evil, i + 1, j, left && (c == from), right && (c == to), lps);
            result %= mod;
        }
        
        dp[i][evilMatch][left][right] = result;
        return result;
    }
    
    // longest prefix that is also a suffix for KMP algorithm
    vector<int> getLPS(string& str) {
        int n = str.size();
        vector<int> lps(n);
        for (int i = 1, j = 0; i < n; i++) {
            while (j > 0 && str[i] != str[j]) {
                j = lps[j - 1];
            }
            if (str[i] == str[j]) {
                j++;
                lps[i] = j;
            }
        }
        return lps;
    }
};
