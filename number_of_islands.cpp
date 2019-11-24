class Solution {
private:
    void findLand(vector<vector<char>>& grid, int row, int col, int& m, int& n) {
        if (row < 0 || col < 0 || row >= m || col >= n || grid[row][col] == '0') {
            return;
        }
        grid[row][col] = '0';
        findLand(grid, row + 1, col, m, n);
        findLand(grid, row - 1, col, m, n);
        findLand(grid, row, col - 1, m, n);
        findLand(grid, row, col + 1, m, n);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) {
            return 0;
        }
        int m = grid.size();
        int n = grid[0].size();
        int result = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    result++;
                    findLand(grid, i, j, m, n);
                }
            }
        }
        return result;
    }
};
