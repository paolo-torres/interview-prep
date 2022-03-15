class Solution {
private:
    bool isWin(vector<string>& board, char c) {
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == c && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
                return true;
            } else if (board[0][i] == c && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
                return true;
            }
        }
        if (board[0][0] == c && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            return true;
        } else if (board[0][2] == c && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            return true;
        }
        return false;
    }
public:
    bool validTicTacToe(vector<string>& board) {
        int xCount = 0;
        int oCount = 0;
        bool xWin = false;
        bool oWin = false;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 'X') {
                    xCount++;
                } else if (board[i][j] == 'O') {
                    oCount++;
                }
            }
        }
        if (xCount < oCount || xCount > oCount + 1) {
            return false;
        }
        if (xCount == oCount) {
            return !isWin(board, 'X');
        } else {
            return !isWin(board, 'O');
        }
        return true;
    }
};
