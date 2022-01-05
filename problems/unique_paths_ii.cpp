class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0][0] == 1) {
            return 0;
        }
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<unsigned int>> data(m, vector<unsigned int>(n));
        data[0][0] = 1;
        for (int i = 1; i < m; i++) {
            if (obstacleGrid[i][0] == 1) {
                data[i][0] = 0;
                break;
            } else {
                data[i][0] = 1;
            }
        }
        for (int j = 1; j < n; j++) {
            if (obstacleGrid[0][j] == 1) {
                data[0][j] = 0;
                break;
            } else {
                data[0][j] = 1;
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    data[i][j] = 0;
                } else {
                    data[i][j] = data[i-1][j] + data[i][j-1];
                }
            }
        }
        if (obstacleGrid[m-1][n-1] == 1) {
            return 0;
        } else {
            return data[m-1][n-1];
        }
    }
};
