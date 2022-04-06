class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> s;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                auto it = s.find(board[i][j]);
                if (it != s.end()) {
                    return false;
                } else {
                    s.insert(board[i][j]);
                }
            }
            s.clear();
        }
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[j][i] == '.') {
                    continue;
                }
                auto it = s.find(board[j][i]);
                if (it != s.end()) {
                    return false;
                } else {
                    s.insert(board[j][i]);
                }
            }
            s.clear();
        }
        for (int iCount = 0; iCount < 9; iCount += 3) {
            for (int jCount = 0; jCount < 9; jCount += 3) {
                for (int i = iCount; i < iCount + 3; i++) {
                    for (int j = jCount; j < jCount + 3; j++) {
                        if (board[i][j] == '.') {
                            continue;
                        }
                        auto it = s.find(board[i][j]);
                        if (it != s.end()) {
                            return false;
                        } else {
                            s.insert(board[i][j]);
                        }
                    }
                }
                s.clear();
            }
        }
        return true;
    }
};
