class Solution {
private:
    int getMines(vector<vector<char>>& board, int x, int y) {
        int mines = 0;
        if (x > 0) {
            if (y > 0) {
                if (board[x-1][y-1] == 'M') {
                    mines++;
                }
            }
            if (board[x-1][y] == 'M') {
                mines++;
            }
            if (y < board[0].size() - 1) {
                if (board[x-1][y+1] == 'M') {
                    mines++;
                }
            }
        }
        if (x < board.size() - 1) {
            if (y > 0) {
                if (board[x+1][y-1] == 'M') {
                    mines++;
                }
            }
            if (board[x+1][y] == 'M') {
                mines++;
            }
            if (y < board[0].size() - 1) {
                if (board[x+1][y+1] == 'M') {
                    mines++;
                }
            }
        }
        if (y > 0) {
            if (board[x][y-1] == 'M') {
                mines++;
            }
        }
        if (y < board[x].size() - 1) {
            if (board[x][y+1] == 'M') {
                mines++;
            }
        }
        return mines;
    }
    void openSquares(vector<vector<char>>& board, int x, int y) {
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) {
            return;
        }
        if (board[x][y] == 'X' || board[x][y] == 'B' || (board[x][y] >= '1' && board[x][y] <= '8')) {
            return;
        }
        if (board[x][y] == 'M') {
            board[x][y] = 'X';
            return;
        }
        int mines = getMines(board, x, y);
        if (mines > 0) {
            board[x][y] = mines + '0';
        } else {
            board[x][y] = 'B';
            for (int i = x - 1; i <= x + 1; i++) {
                for (int j = y - 1; j <= y + 1; j++) {
                    openSquares(board, i, j);
                }
            }
        }
        return;
    }
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        openSquares(board, click[0], click[1]);
        return board;
    }
};
