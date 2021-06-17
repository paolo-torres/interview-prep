// Time: O(m x n x (3 ^ k))
// Space: O(m x n)

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        vector<vector<bool>> visited(m, vector<bool>(n));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (search(board, word, visited, 0, i, j, m, n)) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
private:
    bool search(vector<vector<char>>& board, string word,
        vector<vector<bool>>& visited, int index, int i, int j, int m, int n) {
        if (visited[i][j] || board[i][j] != word[index]) {
            return false;
        }
        visited[i][j] = true;
        
        if (index == word.size() - 1) {
            return true;
        }
        
        if (i > 0) {
            if (search(board, word, visited, index + 1, i - 1, j, m, n)) {
                return true;
            }
        }
        if (i < m - 1) {
            if (search(board, word, visited, index + 1, i + 1, j, m, n)) {
                return true;
            }
        }
        if (j > 0) {
            if (search(board, word, visited, index + 1, i, j - 1, m, n)) {
                return true;
            }
        }
        if (j < n - 1) {
            if (search(board, word, visited, index + 1, i, j + 1, m, n)) {
                return true;
            }
        }
        
        visited[i][j] = false;
        return false;
    }
};
