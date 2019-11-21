class Solution {
private:
    bool findNeighbors(vector<vector<char>>& board, vector<vector<bool>>& visited, string word, int curr, int i, int j) {
        if (!visited[i][j] && board[i][j] == word[curr]) {
            visited[i][j] = true;
            if (curr == word.size() - 1) {
                return true;
            }
            if (i > 0) {
                if (findNeighbors(board, visited, word, curr + 1, i - 1, j)) {
                    return true;
                }
            }
            if (i < board.size() - 1) {
                if (findNeighbors(board, visited, word, curr + 1, i + 1, j)) {
                    return true;
                }
            }
            if (j > 0) {
                if (findNeighbors(board, visited, word, curr + 1, i, j - 1)) {
                    return true;
                }
            }
            if (j < board[0].size() - 1) {
                if (findNeighbors(board, visited, word, curr + 1, i, j + 1)) {
                    return true;
                }
            }
            visited[i][j] = false;
        }
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || word.empty()) {
            return false;
        }
        int row = board.size();
        int col = board[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    if (findNeighbors(board, visited, word, 0, i, j)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
