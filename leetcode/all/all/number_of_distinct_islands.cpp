// To store distinct islands, hash by path from i/j start
// Hash set will naturally ignore duplicate island shapes

// Time: O(m x n)
// Space: O(m x n)

class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        unordered_set<string> result;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    string island = "";
                    dfs(grid, i, j, i, j, m, n, island);
                    result.insert(island);
                }
            }
        }
        
        return result.size();
    }
private:
    void dfs(vector<vector<int>>& grid, int iStart, int jStart,
        int i, int j, int m, int n, string& island) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
            return;
        }
        
        grid[i][j] = 0;
        island += to_string(i - iStart) + to_string(j - jStart);
        
        dfs(grid, iStart, jStart, i - 1, j, m, n, island);
        dfs(grid, iStart, jStart, i + 1, j, m, n, island);
        dfs(grid, iStart, jStart, i, j - 1, m, n, island);
        dfs(grid, iStart, jStart, i, j + 1, m, n, island);
    }
};
