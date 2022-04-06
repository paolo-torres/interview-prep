// Player wins if entire row/col/diagonal marked
// Player 1 increments counts, player 2 decrements counts

// Time: O(1)
// Space: O(n)

class TicTacToe {
public:
    TicTacToe(int n) {
        for (int i = 0; i < n; i++) {
            rows.push_back(0);
            cols.push_back(0);
        }
        diagonal1 = 0;
        diagonal2 = 0;
    }
    
    int move(int row, int col, int player) {
        int curr = player == 1 ? 1 : -1;
        
        rows[row] += curr;
        cols[col] += curr;
        
        if (row == col) {
            diagonal1 += curr;
        }
        
        if (col == cols.size() - row - 1) {
            diagonal2 += curr;
        }
        
        int n = rows.size();
        if (abs(rows[row]) == n || abs(cols[col]) == n
            || abs(diagonal1) == n || abs(diagonal2) == n) {
            return player;
        }
        
        return 0;
    }
private:
    vector<int> rows;
    vector<int> cols;
    int diagonal1;
    int diagonal2;
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
