/*
    'M' unrevealed mine, 'E' empty, 'B' revealed blank, '1'-'8' how many adj mines, 'X' revealed mine
    Also given a click, return board after revealing according to Minesweeper rules

    BFS, if 'M': is mine & stop, if 'E': if has adj mines get # and stop, else search 8 dirs

    Time: O(m x n)
    Space: O(m x n)
*/

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int m = board.size();
        int n = board[0].size();
        
        int x = click[0];
        int y = click[1];
        
        if (board[x][y] == 'M') {
            board[x][y] = 'X';
        } else {
            dfs(board, x, y, m, n);
        }
        
        return board;
    }
private:
    vector<vector<int>> dirs = {
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1}, {0, 1},
        {1, -1}, {1, 0}, {1, 1}
    };
    
    void dfs(vector<vector<char>>& board, int x, int y, int m, int n) {
        if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] != 'E') {
            return;
        }
        
        int mines = getMines(board, x, y, m, n);
        if (mines > 0) {
            board[x][y] = mines + '0';
            return;
        }
        
        board[x][y] = 'B';
        for (int i = 0; i < 8; i++) {
            dfs(board, x + dirs[i][0], y + dirs[i][1], m, n);
        }
    }
    
    int getMines(vector<vector<char>>& board, int x, int y, int m, int n) {
        int count = 0;
        for (int i = x - 1; i <= x + 1; i++) {
            for (int j = y - 1; j <= y + 1; j++) {
                if (i >= 0 && i < m && j >= 0 && j < n && board[i][j] == 'M') {
                    count++;
                }
            }
        }
        return count;
    }
};
