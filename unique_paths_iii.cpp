class Solution {
private:
    int result = 0;
    int empty = 1;
    int xStart = 0;
    int yStart = 0;
    int xEnd = 0;
    int yEnd = 0;
    void findPaths(vector<vector<int>>& grid, int x, int y) {
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] < 0) {
            return;
        }
        if (x == xEnd && y == yEnd) {
            if (empty == 0) {
                result++;
            }
            return;
        }
        grid[x][y] = -2;
        empty--;
        findPaths(grid, x + 1, y);
        findPaths(grid, x - 1, y);
        findPaths(grid, x, y + 1);
        findPaths(grid, x, y - 1);
        grid[x][y] = 0;
        empty++;
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    empty++;
                } else if (grid[i][j] == 1) {
                    xStart = i;
                    yStart = j;
                } else if (grid[i][j] == 2) {
                    xEnd = i;
                    yEnd = j;
                }
            }
        }
        findPaths(grid, xStart, yStart);
        return result;
    }
};
