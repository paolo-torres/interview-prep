class Solution {
private:
    void search(vector<vector<char>>& board, string& word, bool& found, int index, int i, int j, int m, int n) {
        if (board[i][j] == '0' || found) {
            return;
        }
        if (index == word.size()) {
            found = true;
            return;
        }
        char temp = board[i][j];
        board[i][j] = '0';
        if (i > 0 && board[i-1][j] == word[index]) {
            search(board, word, found, index + 1, i - 1, j, m, n);
        }
        if (i < m - 1 && board[i+1][j] == word[index]) {
            search(board, word, found, index + 1, i + 1, j, m, n);
        }
        if (j > 0 && board[i][j-1] == word[index]) {
            search(board, word, found, index + 1, i, j - 1, m, n);
        }
        if (j < n - 1 && board[i][j+1] == word[index]) {
            search(board, word, found, index + 1, i, j + 1, m, n);
        }
        board[i][j] = temp;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> result;
        if (board.empty()) {
            return result;
        }
        unordered_map<char, vector<string>> map;
        for (auto x : words) {
            map[x[0]].push_back(x);
        }
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (map[board[i][j]].size() > 0) {
                    for (auto x : map[board[i][j]]) {
                        bool found = false;
                        search(board, x, found, 1, i, j, m, n);
                        if (found && find(result.begin(), result.end(), x) == result.end()) {
                            result.push_back(x);
                        }
                    }
                }
            }
        }
        return result;
    }
};
