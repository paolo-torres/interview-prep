class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0][0] == 1) {
            return 0;
        }
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<unsigned int>> temp(m, vector<unsigned int>(n));
        temp[0][0] = 1;
        for (int i = 1; i < m; i++) {
            if (obstacleGrid[i][0] == 0 && obstacleGrid[i-1][0] == 0) {
                temp[i][0] = temp[i-1][0];
            } else {
                temp[i][0] = 0;
            }
        }
        for (int i = 1; i < n; i++) {
            if (obstacleGrid[0][i] == 0 && obstacleGrid[0][i-1] == 0) {
                temp[0][i] = temp[0][i-1];
            } else {
                temp[0][i] = 0;
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 0) {
                    temp[i][j] = temp[i-1][j] + temp[i][j-1];
                } else {
                    temp[i][j] = 0;
                }
            }
        }
        return temp[m-1][n-1];
    }
};
