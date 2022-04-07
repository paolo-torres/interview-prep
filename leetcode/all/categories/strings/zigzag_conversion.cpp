class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 0 || s.size() == 0) {
            return "";
        }
        if (numRows == 1 || s.size() == 1) {
            return s;
        }
        int maxCols = s.size();
        char arr[numRows][maxCols];
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < maxCols; j++) {
                arr[i][j] = '\0';
            }
        }
        auto it = s.begin();
        int row = 0;
        int col = 0;
        while (it != s.end()) {
            while (row < numRows && it != s.end()) {
                arr[row][col] = *it;
                ++it;
                row++;
            }
            row--;
            while (row > 0 && it != s.end()) {
                row--;
                col++;
                arr[row][col] = *it;
                ++it;
            }
            row++;
        }
        string result;
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j <= col; j++) {
                if (arr[i][j] != '\0') {
                    result.push_back(arr[i][j]);
                }
            }
        }
        return result;
    }
};
