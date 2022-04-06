// Hash map {index, size of island}, for each "0" flip + find largest

// Time: O(n^2)
// Space: O(n^2)

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int index = 2;
        
        unordered_map<int, int> m;
        m[0] = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int size = getSize(grid, index, i, j, n);
                    m[index] = size;
                    index++;
                }
            }
        }
        
        int result = m[2] ? m[2] : 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> s;
                    
                    s.insert(i > 0 ? grid[i - 1][j] : 0);
                    s.insert(i < n - 1 ? grid[i + 1][j] : 0);
                    s.insert(j > 0 ? grid[i][j - 1] : 0);
                    s.insert(j < n - 1 ? grid[i][j + 1] : 0);
                    
                    int newSize = 1;
                    for (auto it = s.begin(); it != s.end(); it++) {
                        newSize += m[*it];
                    }
                    result = max(result, newSize);
                }
            }
        }
        
        return result;
    }
private:
    int getSize(vector<vector<int>>& grid, int index, int i, int j, int n) {
        if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] != 1) {
            return 0;
        }
        grid[i][j] = index;
        return 1 + getSize(grid, index, i - 1, j, n)
            + getSize(grid, index, i + 1, j, n)
            + getSize(grid, index, i, j - 1, n)
            + getSize(grid, index, i, j + 1, n);
    }
};
