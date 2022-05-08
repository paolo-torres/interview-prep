/*
    Search for a target value in row & col sorted matrix

    Brute force O(m x n) search -> optimize w/:
    search space reduction, start top right & go to bottom left

    Time: O(m + n)
    Space: O(1)
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int i = 0;
        int j = n - 1;
        
        while (i <= m - 1 && j >= 0) {
            if (matrix[i][j] < target) {
                i++;
            } else if (matrix[i][j] > target) {
                j--;
            } else {
                return true;
            }
        }
        
        return false;
    }
};
