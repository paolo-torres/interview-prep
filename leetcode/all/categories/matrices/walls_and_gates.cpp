// BFS traversal, shortest path from each gate to all empty rooms
// Each gate only looks at within 1 space, then next gate, guarantees shortest

// Time: O(m x n)
// Space: O(m x n)

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size();
        int n = rooms[0].size();
        
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rooms[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        
        while (!q.empty()) {
            auto cell = q.front();
            q.pop();
            
            int row = cell.first;
            int col = cell.second;
            
            for (int i = 0; i < 4; i++) {
                int r = row + directions[i][0];
                int c = col + directions[i][1];
                
                if (r < 0 || r >= m || c < 0 || c >= n || rooms[r][c] != INT_MAX) {
                    continue;
                }
                
                rooms[r][c] = rooms[row][col] + 1;
                q.push({r, c});
            }
        }
    }
private:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
};
