/*
    Given matrix, return max # of points we can achieve
    To gain pick one cell in each row, but lose points if too far from prev cell
    Picking (r,c) gains points[r][c], but: (r,c1) & (r+1,c2) -> lose abs(c1-c2)

    Start with DP, compare each spot with above 3, recurrence relation:
    dp[i][j] = max(dp[i - 1][k] + points[i][j] - abs(j - k)) for each 0 <= k < j

    Optimize: Don't compare every prev, instead store max of left & rights

    Time: O(m x n)
    Space: O(n)
*/

// class Solution {
// public:
//     long long maxPoints(vector<vector<int>>& points) {
//         int m = points.size();
//         int n = points[0].size();
//         vector<vector<long long>> dp(m, vector<long long>(n));
//         for (int j = 0; j < n; j++) {
//             dp[0][j] = points[0][j];
//         }
//         for (int i = 1; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 for (int k = 0; k < n; k++) {
//                     long long gain = dp[i - 1][k] + points[i][j];
//                     long long lose = abs(k - j);
//                     dp[i][j] = max(dp[i][j], gain - lose);
//                 }
//             }
//         }
//         long long result = 0;
//         for (int j = 0; j < n; j++) {
//             result = max(result, dp[m - 1][j]);
//         }
//         return result;
//     }
// };

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();
        
        vector<long long> pre(n);
        for (int j = 0; j < n; j++) {
            pre[j] = points[0][j];
        }
        
        for (int i = 0; i < m - 1; i++) {
            vector<long long> left(n);
            vector<long long> right(n);
            vector<long long> curr(n);
            
            left[0] = pre[0];
            right[n - 1] = pre[n - 1];
            
            for (int j = 1; j < n; j++) {
                left[j] = max(left[j - 1] - 1, pre[j]);
            }
            for (int j = n - 2; j >= 0; j--) {
                right[j] = max(right[j + 1] - 1, pre[j]);
            }
            for (int j = 0; j < n; j++) {
                curr[j] = points[i + 1][j] + max(left[j], right[j]);
            }
            
            pre = curr;
        }
        
        long long result = 0;
        for (int j = 0; j < n; j++) {
            result = max(result, pre[j]);
        }
        return result;
    }
};
