class Solution {
private:
    bool search(vector<vector<char>>& board, vector<vector<bool>>& visited, string word, int index, int i, int j) {
        if (board[i][j] == word[index] && !visited[i][j]) {
            visited[i][j] = true;
            if (index == word.size() - 1) {
                return true;
            }
            if (i > 0) {
                if (search(board, visited, word, index + 1, i - 1, j)) {
                    return true;
                }
            }
            if (i < board.size() - 1) {
                if (search(board, visited, word, index + 1, i + 1, j)) {
                    return true;
                }
            }
            if (j > 0) {
                if (search(board, visited, word, index + 1, i, j - 1)) {
                    return true;
                }
            }
            if (j < board[0].size() - 1) {
                if (search(board, visited, word, index + 1, i, j + 1)) {
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
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (search(board, visited, word, 0, i, j)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
