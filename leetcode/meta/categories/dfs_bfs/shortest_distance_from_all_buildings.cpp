// BFS from houses to empty land, can use input itself instead of visited
// Change visited land to -1, next BFS only visit -1, then change to -2, etc.
// Allows us to avoid visiting cells that can't reach all houses
// This strategy also functions as a visited check (only visit emptyLandValue)

// Time: O(m^2 x n^2) -> traverse all reachable land for each house
// Space: O(m x n)

class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> total(m, vector<int>(n, 0));
        
        int emptyLandValue = 0;
        int result = INT_MAX;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    result = INT_MAX;
                    
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    
                    int steps = 0;
                    
                    while (!q.empty()) {
                        steps++;
                        
                        for (int level = q.size(); level > 0; level--) {
                            int currRow = q.front().first;
                            int currCol = q.front().second;
                            q.pop();
                            
                            for (int i = 0; i < directions.size(); i++) {
                                int nextRow = currRow + directions[i][0];
                                int nextCol = currCol + directions[i][1];
                                
                                if (nextRow >= 0 && nextRow < m
                                    && nextCol >= 0 && nextCol < n
                                    && grid[nextRow][nextCol] == emptyLandValue) {
                                    
                                    grid[nextRow][nextCol]--;
                                    total[nextRow][nextCol] += steps;
                                    
                                    q.push({nextRow, nextCol});
                                    result = min(result, total[nextRow][nextCol]);
                                }
                            }
                        }
                    }
                    
                    emptyLandValue--;
                }
            }
        }
        
        if (result == INT_MAX) {
            return -1;
        }
        return result;
    }
};
