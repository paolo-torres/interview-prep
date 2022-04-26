/*
    'A': absent, 'L': late, 'P': present
    Attendance award if: 'A' < 2 & consecutive'L' < 3
    Given n, return # of records of length n that can get award
    Ex. n = 2 -> 8, "PP","AP","PA","LP","PL","AL","LA","LL" (not "AA")

    DFS + memo, generate all strings, try 'P', 'A', 'L' w/ the validations

    Time: O(n) -> from 2^n, not 3^n because A only generated once
    Space: O(n)
*/

class Solution {
public:
    int checkRecord(int n) {
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3)));
        return dfs(n, 0, 0, dp);
    }
private:
    int mod = pow(10, 9) + 7;
    
    int dfs(int n, int totalA, int continuousL, vector<vector<vector<int>>>& dp) {
        if (n == 0) {
            return 1;
        }
        if (dp[n][totalA][continuousL] != 0) {
            return dp[n][totalA][continuousL];
        }
        
        // choose 'P'
        long result = dfs(n - 1, totalA, 0, dp);
        if (totalA == 0) {
            // choose 'A'
            result += dfs(n - 1, totalA + 1, 0, dp);
        }
        if (continuousL < 2) {
            // choose 'L'
            result += dfs(n - 1, totalA, continuousL + 1, dp);
        }
        
        dp[n][totalA][continuousL] = (int) (result % mod);
        return (int) (result % mod);
    }
};
