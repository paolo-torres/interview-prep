/*
    reachTheEnd has the following parameters:
        string grid[r]: the rows of the grid
        int maxTime: the maximum time to complete the traversal
    
    Returns:
        string: the final strin; either 'Yes' or 'No'
*/

class Solution {
public:
    string reachTheEnd(vector<vector<char>>& grid, int maxTime) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = '#';

        int count = 0;

        while (!q.empty()) {
            int size = q.size();
            count++;

            for (int i = 0; i < size; i++) {
                int x = q.front()[0];
                int y = q.front()[1];
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int dx = x + dirs[i][0];
                    int dy = y + dirs[i][1];

                    if (dx < 0 || dx >= m || dy < 0 || dy >= n) {
                        continue;
                    }

                    grid[dx][dy] = '#';
                    q.push({dx, dy});
                }
            }
        }

        count--;
        if (count <= maxTime) {
            return "Yes";
        } else {
            return "No";
        }
    }
private:
    vector<vector<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
};
