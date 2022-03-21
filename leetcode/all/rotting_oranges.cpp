class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        queue<int> q;
        map<int, int> depth;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 2) {
                    q.push(i * col + j);
                    depth.insert(make_pair(i * col + j, 0));
                }
            }
        }
        vector<int> dirRow = {-1, 0, 1, 0};
        vector<int> dirCol = {0, 1, 0, -1};
        int pos = 0;
        int r = 0;
        int c = 0;
        int result = 0;
        while (!q.empty()) {
            pos = q.front();
            q.pop();
            r = pos / col;
            c = pos % col;
            for (int i = 0; i < 4; i++) {
                int newRow = r + dirRow[i];
                int newCol = c + dirCol[i];
                if (newRow >= 0 && newRow < row && newCol >= 0 && newCol < col && grid[newRow][newCol] == 1) {
                    grid[newRow][newCol] = 2;
                    int newPos = newRow * col + newCol;
                    q.push(newPos);
                    depth.insert(make_pair(newPos, depth.find(pos)->second + 1));
                    result = depth.find(newPos)->second;
                }
            }
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return result;
    }
};
