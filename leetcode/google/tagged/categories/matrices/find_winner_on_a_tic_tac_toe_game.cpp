/*
    Tic-tac-toe, given 2D array of moves, return winner
    Ex. moves = [[0,0],[2,0],[1,1],[2,1],[2,2]] -> "A"

    Track moves made in row/col/diagonal, switch b/w players w/ 1/-1, winner at n

    Time: O(m) -> m = number of input moves
    Space: O(n) -> n = size of the board
*/

class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        // size of board
        int n = 3;
        
        vector<int> rows(n);
        vector<int> cols(n);
        
        int diagonal = 0;
        int antiDiagonal = 0;
        
        // 2 players having values 1 and -1
        int player = 1;
        
        for (int i = 0; i < moves.size(); i++) {
            int row = moves[i][0];
            int col = moves[i][1];
            
            // update row and column values
            rows[row] += player;
            cols[col] += player;
            
            // if placed on either diagonal
            if (row == col) {
                diagonal += player;
            }
            if (row + col == n - 1) {
                antiDiagonal += player;
            }
            
            // wining condition: any 3 in a row/col/diagonal
            if (abs(rows[row]) == n || abs(cols[col]) == n
                || abs(diagonal) == n || abs(antiDiagonal) == n) {
                return player == 1 ? "A" : "B";
            }
            
            // other player's turn
            player *= -1;
        }
        
        // if grid full draw, else pending
        return moves.size() == n * n ? "Draw" : "Pending";
    }
};
