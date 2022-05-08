/*
    Given matrix, return true if every diagonal has same elements

    Optimal: compare with top left neighbor
    Follow up: what if can only load 1 row at a time?
    Answer: Hash map {i-j -> mat[i][j]}
    If not exists insert, else if not equal return false

    Time: O(m x n)
    Space: O(1)
*/

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] != matrix[i - 1][j - 1]) {
                    return false;
                }
            }
        }
        
        return true;
    }
};
