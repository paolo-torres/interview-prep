// (1) crush all horizontally, (2) crush all vertically, (3) apply gravity, (4) repeat

// Time: O((m x n) ^ 2)
// Space: O(1)

class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        bool todo = false;
        
        // crush horizontally (mark as negative)
        for (int i = 0; i < m; i++) {
            for (int j = 0; j + 2 < n; j++) {
                int val = abs(board[i][j]);
                if (val != 0 && val == abs(board[i][j + 1]) && val == abs(board[i][j + 2])) {
                    board[i][j] = -val;
                    board[i][j + 1] = -val;
                    board[i][j + 2] = -val;
                    todo = true;
                }
            }
        }
        
        // crush vertically (mark as negative)
        for (int i = 0; i + 2 < m; i++) {
            for (int j = 0; j < n; j++) {
                int val = abs(board[i][j]);
                if (val != 0 && val == abs(board[i + 1][j]) && val == abs(board[i + 2][j])) {
                    board[i][j] = -val;
                    board[i + 1][j] = -val;
                    board[i + 2][j] = -val;
                    todo = true;
                }
            }
        }
        
        // drop vertically
        for (int j = 0; j < n; j++) {
            int row = m - 1;
            for (int i = m - 1; i >= 0; i--) {
                if (board[i][j] > 0) {
                    board[row][j] = board[i][j];
                    row--;
                }
            }
            for (int i = row; i >= 0; i--) {
                board[i][j] = 0;
            }
        }
        
        if (todo) {
            return candyCrush(board);
        }
        return board;
    }
};
