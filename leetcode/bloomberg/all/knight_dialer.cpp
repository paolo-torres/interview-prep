// DFS -> optimize w/ DP, cache repeated paths

// Time: O(n) -> O(4 x 3 x n) = O(n)
// Space: O(n) -> O(4 x 3 x n) = O(n)

class Solution {
public:
    int knightDialer(int n) {
        vector<vector<vector<long>>> dp(n + 1, vector<vector<long>>(4, vector<long>(3)));
        long result = 0;
        
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                result = (result + dfs(n, dp, i, j)) % max;
            }
        }
        
        return (int) result;
    }
private:
    int max = pow(10, 9) + 7;
    
    long dfs(int n, vector<vector<vector<long>>>& dp, int i, int j) {
        if (i < 0 || i >= 4 || j < 0 || j >= 3 || (i == 3 && j != 1)) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        
        if (dp[n][i][j] > 0) {
            return dp[n][i][j];
        }
        
        dp[n][i][j] = dfs(n - 1, dp, i - 1, j - 2) % max
            + dfs(n - 1, dp, i - 2, j - 1) % max
            + dfs(n - 1, dp, i - 1, j + 2) % max
            + dfs(n - 1, dp, i - 2, j + 1) % max
            + dfs(n - 1, dp, i + 1, j - 2) % max
            + dfs(n - 1, dp, i + 2, j - 1) % max
            + dfs(n - 1, dp, i + 1, j + 2) % max
            + dfs(n - 1, dp, i + 2, j + 1) % max;
        
        return dp[n][i][j];
    }
};
