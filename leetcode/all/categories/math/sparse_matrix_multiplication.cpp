// Create non-zero version of mat1, multiply with mat2 & skipping zeros

// Time: O(m x n x p)
// Space: O(m x n + m x p)

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int m = mat1.size();
        int n = mat2.size();
        int p = mat2[0].size();
        
        vector<vector<int>> mat1NoZeros(m);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat1[i][j] != 0) {
                    mat1NoZeros[i].push_back(j);
                }
            }
        }
        
        vector<vector<int>> result(m, vector<int>(p, 0));
        
        for (int i = 0; i < m; i++) {
            for (int l = 0; l < mat1NoZeros[i].size(); l++) {
                int k = mat1NoZeros[i][l];
                for (int j = 0; j < p; j++) {
                    if (mat2[k][j] != 0) {
                        result[i][j] += mat1[i][k] * mat2[k][j];
                    }
                }
            }
        }
        
        return result;
    }
};
