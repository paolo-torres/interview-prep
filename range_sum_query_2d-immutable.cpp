class NumMatrix {
private:
    vector<vector<int>> data;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty()) {
            return;
        }
        data = matrix;
        for (int i = 1; i < matrix.size(); i++) {
            data[i][0] = matrix[i][0] + data[i-1][0];
        }
        for (int j = 1; j < matrix[0].size(); j++) {
            data[0][j] = matrix[0][j] + data[0][j-1];
        }
        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[0].size(); j++) {
                data[i][j] = matrix[i][j] + data[i-1][j] + data[i][j-1] - data[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int a = 0;
        int b = 0;
        int c = 0;
        if (col1 != 0) {
            a = data[row2][col1-1];
        }
        if (row1 != 0) {
            b = data[row1-1][col2];
        }
        if (col1 != 0 && row1 != 0) {
            c = data[row1-1][col1-1];
        }
        return data[row2][col2] - a - b + c;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
