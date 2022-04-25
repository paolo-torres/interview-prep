/*
    Given a rectangle of size m x n:
    Return min # of integer-sided squares that tile the rectangle

    Go thru every pt in rectangle, cover a (k x k) square at (i, j)
    Try every possible size of (k x k), where k = min(m - i, n - j)

    Time: O(m x n x min(m, n)^2) -> trying to place (k x k) everywhere
    Space: O(m x n)
*/

class Solution {
public:
    int tilingRectangle(int n, int m) {
        vector<vector<bool>> covered(n, vector<bool>(m));
        int result = INT_MAX;
        dfs(0, 0, covered, 0, result);
        return result;
    }
private:
    void dfs(int i, int j, vector<vector<bool>>& covered, int curr, int& result) {
        int m = covered.size();
        int n = covered[0].size();
        
        // if worse than our best answer so far, return
        if (curr >= result) {
            return;
        }
        // base case, covered entire rectangle
        if (i >= m) {
            result = curr;
            return;
        }
        // covered entire column, move to next row
        if (j >= n) {
            dfs(i + 1, 0, covered, curr, result);
            return;
        }
        // if (i, j) already covered, move to next pt
        if (covered[i][j]) {
            dfs(i, j + 1, covered, curr, result);
            return;
        }
        
        // try all possible square sizes at (i, j), take min everytime
        for (int k = min(m - i, n - j); k > 0; k--) {
            if (!isAvailable(covered, i, j, k)) {
                break;
            }
            cover(covered, i, j, k);
            dfs(i, j + 1, covered, curr + 1, result);
            uncover(covered, i, j, k);
        }
    }
    
    bool isAvailable(vector<vector<bool>>& covered, int i, int j, int k) {
        for (int ik = 0; ik < k; ik++) {
            for (int jk = 0; jk < k; jk++) {
                if (covered[i + ik][j + jk]) {
                    return false;
                }
            }
        }
        return true;
    }
    
    void cover(vector<vector<bool>>& covered, int i, int j, int k) {
        for (int ik = 0; ik < k; ik++) {
            for (int jk = 0; jk < k; jk++) {
                covered[i + ik][j + jk] = true;
            }
        }
    }
    
    void uncover(vector<vector<bool>>& covered, int i, int j, int k) {
        for (int ik = 0; ik < k; ik++) {
            for (int jk = 0; jk < k; jk++) {
                covered[i + ik][j + jk] = false;
            }
        }
    }
};
