// Adjust row/col at boundaries (last col/row & first row/col)
// Direction up when row + col is even, down when sum is odd

// Time: O(m x n)
// Space: O(m x n)

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int row = 0;
        int col = 0;
        int m = mat.size();
        int n = mat[0].size();
        
        vector<int> result(m * n, 0);
        
        for (int i = 0; i < result.size(); i++) {
            result[i] = mat[row][col];
            
            if ((row + col) % 2 == 0) {
                if (col == n - 1) {
                    row++;
                } else if (row == 0) {
                    col++;
                } else {
                    row--;
                    col++;
                }
            } else {
                if (row == m - 1) {
                    col++;
                } else if (col == 0) {
                    row++;
                } else {
                    row++;
                    col--;
                }
            }
        }
        
        return result;
    }
};
