/*
    Given binary matrix, choose 1 cell to flip, all 4 neighbors flip (if exists)
    Neighbors if they share 1 edge, return min # of steps to convert to 0 matrix
    Ex. mat = [[0,0],[0,1]] -> 3, flip (1,0), then (0,1), then (1,1)

    Convert matrix to int, for each bit, flip it + neighbors, BFS until all 0s

    Time: O(m x n x 2 ^ (m x n))
    Space: O(2 ^ (m x n))
*/

class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        int start = 0;
        // convert matrix to an int
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                /*
                    sum(cell << (i * n + j))
                    mat = [[0,0],[0,1]] -> 0b1000
                    mat[0][0] = 0 -> 0th bit -> 0
                    mat[0][1] = 0 -> 1st bit -> 0
                    mat[1][0] = 0 -> 2nd bit -> 0
                    mat[1][1] = 1 -> 3rd bit -> 1
                    |= same as +=, x << y same as x * 2^y
                */
                start |= mat[i][j] << (i * n + j);
            }
        }
        
        queue<int> q;
        q.push(start);
        
        unordered_set<int> seen;
        seen.insert(start);
        
        int result = 0;
        while (!q.empty()) {
            int count = q.size();
            for (int i = 0; i < count; i++) {
                int curr = q.front();
                q.pop();
                
                // zero matrix found
                if (curr == 0) {
                    return result;
                }
                
                // traverse m x n bits of curr
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < n; j++) {
                        int next = curr;
                        // flip cell (i, j) & its neighbors
                        for (int k = 0; k < 5; k++) {
                            int row = i + dirs[k][0];
                            int col = j + dirs[k][1];
                            if (row < 0 || row >= m || col < 0 || col >= n) {
                                continue;
                            }
                            // next ^ 1 << k -> flip kth bit of next
                            // same as flipping corresponding cell in (i,j) in mat
                            next ^= 1 << (row * n + col);
                        }
                        // if we've seen this already, do not add to queue
                        if (seen.find(next) == seen.end()) {
                            seen.insert(next);
                            q.push(next);
                        }
                    }
                }
            }
            result++;
        }
        return -1;
    }
private:
    vector<vector<int>> dirs = {{0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
};
