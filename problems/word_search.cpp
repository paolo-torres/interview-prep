// Time: O(mn)
// Space: O(mn)

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (search(board, visited, word, 0, i, j, m, n)) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
private:
    bool search(vector<vector<char>>& board, vector<vector<bool>>& visited,
        string word, int index, int i, int j, int m, int n) {
        
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return false;
        }
        if (visited[i][j] == true || board[i][j] != word[index]) {
            return false;
        }
        
        if (index == word.size() - 1) {
            return true;
        }
        
        visited[i][j] = true;
        if (search(board, visited, word, index + 1, i - 1, j, m, n)) {
            return true;
        }
        if (search(board, visited, word, index + 1, i + 1, j, m, n)) {
            return true;
        }
        if (search(board, visited, word, index + 1, i, j - 1, m, n)) {
            return true;
        }
        if (search(board, visited, word, index + 1, i, j + 1, m, n)) {
            return true;
        }
        visited[i][j] = false;
        
        return false;
    }
};
