// BFS traversal, A* follow-up with F cost + min heap

// Time: O(n^2)
// Space: O(n^2)

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;
        }
        grid[0][0] = 1;
        
        vector<vector<int>> directions = {
            {-1, -1}, {-1, 0}, {-1, 1},
            {0, -1}, {0, 1},
            {1, -1}, {1, 0}, {1, 1}
        };
        
        queue<pair<int, int>> q;
        q.push({0, 0});
        
        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();
            
            int row = curr.first;
            int col = curr.second;
            
            if (row == n - 1 && col == n - 1) {
                return grid[n - 1][n - 1];
            }
            
            for (int i = 0; i < directions.size(); i++) {
                int newRow = row + directions[i][0];
                int newCol = col + directions[i][1];
                
                if (newRow >= 0 && newRow < n
                   && newCol >= 0 && newCol < n
                   && grid[newRow][newCol] == 0) {
                    q.push({newRow, newCol});
                    grid[newRow][newCol] = grid[row][col] + 1;
                }
            }
        }
        
        return -1;
    }
};
