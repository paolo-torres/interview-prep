/*
    Given binary matrix, can choose any row/col & flip all bits
    Return true if possible to remove all 1's from grid
    Ex. grid = [[0,1,0],[1,0,1],[0,1,0]]

    Main idea: fix 1st row column-wise, rest of the rows need to be "fixable"
    Once fixed, shouldn't have to be fixed again, else impossible case

    Time: O(m x n)
    Space: O(1)
*/

class Solution {
public:
    bool removeOnes(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // for all cells in 1st row with 1, flip entire column
        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 1) {
                // flip column
                for (int i = 0; i < m; i++) {
                    grid[i][j] = !grid[i][j];
                }
            }
        }
        
        // at this point, all other rows should be either all 0's or 1's
        for (int i = 1; i < m; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                sum += grid[i][j];
            }
            if (sum != 0 && sum != n) {
                return false;
            }
        }
        
        return true;
    }
};
