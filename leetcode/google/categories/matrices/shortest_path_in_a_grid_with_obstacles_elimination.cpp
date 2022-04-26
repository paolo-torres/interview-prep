/*
    Given matrix, 0 empty, 1 obstacle:
    Return min steps to walk from upper left to lower right
    Can remove at most k obstacles
    
    BFS traversal, track k & # steps in queue, remove obstacle if k > 0

    Time: O(m x n x k)
    Space: O(m x n x k)
*/

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        queue<vector<int>> q;
        // (x, y, # of obstacles can still remove, # of steps)
        q.push({0, 0, k, 0});
        
        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>
                                            (n, vector<bool>(k + 1)));
        visited[0][0][k] = 1;
        
        while (!q.empty()) {
            vector<int> curr = q.front();
            int row = curr[0];
            int col = curr[1];
            int k = curr[2];
            int steps = curr[3];
            q.pop();
            
            if (row == m - 1 && col == n - 1) {
                return steps;
            }
            
            for (int i = 0; i < 4; i++) {
                int x = row + dirs[i][0];
                int y = col + dirs[i][1];
                
                if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y][k]) {
                    continue;
                }
                
                if (grid[x][y] == 1 && k > 0) {
                    q.push({x, y, k - 1, steps + 1});
                } else if (grid[x][y] == 0) {
                    q.push({x, y, k, steps + 1});
                }
                visited[x][y][k] = true;
            }
        }
        
        return -1;
    }
private:
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
};
