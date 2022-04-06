// Time: O(n)
// Space: O(n)

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (original.size() != m * n) {
            vector<vector<int>> empty;
            return empty;
        }
        
        int row = 0;
        int col = 0;
        
        vector<vector<int>> result(m, vector<int>(n));
        
        for (int i = 0; i < original.size(); i++) {
            result[row][col] = original[i];
            col++;
            if (col == n) {
                col = 0;
                row++;
            }
        }
        
        return result;
    }
};
