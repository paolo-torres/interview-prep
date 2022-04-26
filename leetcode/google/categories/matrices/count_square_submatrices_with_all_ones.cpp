/*
    Given matrix of 1s & 0s, return how many square submatrices have all 1s

    Subproblems = smaller submatrices, solutions make up future calculations
    Optimal substructure, DP, think about "square combos", any 0 ends combo
    Combo depends on all elements, combo only as strong as weakest link
    Recurrence relation: dp[i] += min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1])
    
    1 1 0 0 0         1 1 0 0 0
    1 1 1 1 1         1 2 1 1 1
    0 1 1 1 1   -->   0 1 2 2 2
    0 1 1 1 1         0 1 2 3 3
    0 0 1 0 1         0 0 1 0 1

    Time: O(m x n)
    Space: O(1)
*/

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int result = 0;
        
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 1) {
                    if (i == 0 || j == 0) {
                        result++;
                    } else {
                        int val = min(matrix[i - 1][j - 1],
                                  min(matrix[i - 1][j], matrix[i][j - 1])) + matrix[i][j];
                        result += val;
                        matrix[i][j] = val;
                    }
                }
            }
        }
        
        return result;
    }
};
