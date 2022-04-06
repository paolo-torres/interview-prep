// For any move, need to check both final & transitional spots
// Track moves independently for each piece
// Position is blocked if (1) final + closer, or (2) transitional + same
// Can stop if (1) position is unoccupied, & (2) others already went thru

class Solution {
public:
    int countCombinations(vector<string>& pieces, vector<vector<int>>& positions) {
        return helper(pieces, positions, 0);
    }
private:
    int helper(vector<string>& pieces, vector<vector<int>>& positions, int pieceIndex) {
        if (pieceIndex >= pieces.size()) {
            return 1;
        }
        
        int xCurr = positions[pieceIndex][0] - 1;
        int yCurr = positions[pieceIndex][1] - 1;
        
        int result = 0;
        
        for (int d = 0; d < 8; d++) {
            if ((d < 4 && pieces[pieceIndex] == "bishop") || (d >= 4 && pieces[pieceIndex] == "rook")) {
                continue;
            }
            
            bool blocked = false;
            // first move is "stay at start"
            int step = result == 0 ? 1 : 2;
            
            while (!blocked) {
                int xNext = xCurr + (step - 1) * dirs[d][0];
                int yNext = yCurr + (step - 1) * dirs[d][1];
                
                // check if move is within bounds
                if (min(xNext, yNext) < 0 || max(xNext, yNext) > 7) {
                    break;
                }
                
                bool canStop = true;
                for (int p = 0; p < pieceIndex; p++) {
                    // can stop if no other pieces at that spot/already went thru
                    canStop &= board[p][xNext][yNext] >= 0 && board[p][xNext][yNext] < step;
                    
                    // blocked if (1) closer piece will get there first or
                    // (2) piece going thru that spot will get there same time
                    blocked |= (board[p][xNext][yNext] < 0 && -board[p][xNext][yNext] <= step) || (board[p][xNext][yNext] == step);
                }
                
                if (canStop) {
                    // mark w/ negative steps to signify spot is occupied
                    board[pieceIndex][xNext][yNext] = -step;
                    result += helper(pieces, positions, pieceIndex + 1);
                }
                
                // unmark current cell, no longer occupied
                board[pieceIndex][xNext][yNext] = step;
                
                step++;
            }
            
            // clear board for this piece
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    board[pieceIndex][i][j] = 0;
                }
            }
        }
        
        return result;
    }

    int board[4][8][8] = {};
    int dirs[8][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
};
