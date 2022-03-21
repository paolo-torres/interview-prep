// Time: O(9^m), m = number of missing cells
// Space: O(m)

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
private:
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        if (isValid(board, i, j, c)) {
                            board[i][j] = c;
                            if (solve(board)) {
                                return true;
                            } else {
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isValid(vector<vector<char>>& board, int i, int j, char c) {
        for (int row = 0; row < 9; row++) {
            if (board[row][j] == c) {
                return false;
            }
        }
        
        for (int col = 0; col < 9; col++) {
            if (board[i][col] == c) {
                return false;
            }
        }
        
        int regionRow = (i / 3) * 3;
        int regionCol = (j / 3) * 3;
        
        for (int row = regionRow; row < regionRow + 3; row++) {
            for (int col = regionCol; col < regionCol + 3; col++) {
                if (board[row][col] == c) {
                    return false;
                }
            }
        }
        
        return true;
    }
};
