// Pick mid col, find max in col, if peak return, else binary search
// Binary search works bc if neighbor > max in col, peak must exist in that half

// Time: O(log n)
// Space: O(1)

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        int low = 0;
        int high = n - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            int maxRow = 0;
            for (int i = 0; i < m; i++) {
                if (mat[maxRow][mid] < mat[i][mid]) {
                    maxRow = i;
                }
            }
            
            if ((mid == 0 || mat[maxRow][mid] > mat[maxRow][mid - 1])
                && (mid == n - 1 || mat[maxRow][mid] > mat[maxRow][mid + 1])) {
                return {maxRow, mid};
            } else if (mid > 0 && mat[maxRow][mid - 1] > mat[maxRow][mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return {-1, -1};
    }
};
