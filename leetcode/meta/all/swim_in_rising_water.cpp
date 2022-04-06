// Shortest path w/ min heap: at every step, find lowest water level to move fwd

// Time: O(n^2 log n)
// Space: O(n^2)

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 1) {
            return 0;
        }
        
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        visited[0][0] = true;
        
        vector<int> dirs({-1, 0, 1, 0, -1});
        
        int result = max(grid[0][0], grid[n - 1][n - 1]);
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({result, 0, 0});
        
        while (!pq.empty()) {
            vector<int> curr = pq.top();
            pq.pop();
            
            result = max(result, curr[0]);
            
            for (int i = 0; i < 4; i++) {
                int row = curr[1] + dirs[i];
                int col = curr[2] + dirs[i + 1];
                
                if (row >= 0 && row < n && col >= 0 && col < n && !visited[row][col]) {
                    if (row == n - 1 && col == n - 1) {
                        return result;
                    }
                    
                    pq.push({grid[row][col], row, col});
                    visited[row][col] = true;
                }
            }
        }
        
        return -1;
    }
};
