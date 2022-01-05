// Time: O(m x n)
// Space: O(m x n)

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int result = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    explore(grid, i, j, m, n);
                    result++;
                }
            }
        }
        
        return result;
    }
private:
    void explore(vector<vector<char>>& grid, int i, int j, int m, int n) {
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';
        explore(grid, i - 1, j, m, n);
        explore(grid, i + 1, j, m, n);
        explore(grid, i, j - 1, m, n);
        explore(grid, i, j + 1, m, n);
    }
};
