class Solution {
private:
    void findLand(vector<vector<char>>& grid, int i, int j, int m, int n) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';
        findLand(grid, i - 1, j, m, n);
        findLand(grid, i + 1, j, m, n);
        findLand(grid, i, j - 1, m, n);
        findLand(grid, i, j + 1, m, n);
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
