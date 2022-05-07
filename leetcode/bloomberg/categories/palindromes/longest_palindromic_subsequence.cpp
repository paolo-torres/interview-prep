/*
    Given string s, find the longest palindromic subsequence (LPS)

    If helper(i, j) is longest LPS of s[i...j], then we have 2 options:
    1. if s[i] = s[j], then chars match, so LPS here is inner LPS + 2
    2. if s[i] != s[j], then don't match, so LPS is max of LPS w/ i or w/ j

    Time: O(n^2)
    Space: O(n^2) -> optimize space to O(n) since only need 2 states
*/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> memo(1000, vector<int>(1000));
        return helper(s, memo, 0, s.size() - 1);
    }
private:
    int helper(string& s, vector<vector<int>>& memo, int i, int j) {
        // return 0 since empty string
        if (i > j) {
            return 0;
        }
        // return 1 since 1 char palindrome
        if (i == j) {
            return 1;
        }
        if (memo[i][j] != 0) {
            return memo[i][j];
        }
        if (s[i] == s[j]) {
            memo[i][j] = helper(s, memo, i + 1, j - 1) + 2;
            return memo[i][j];
        }
        memo[i][j] = max(helper(s, memo, i + 1, j), helper(s, memo, i, j - 1));
        return memo[i][j];
    }
};

// class Solution {
// public:
//     int longestPalindromeSubseq(string s) {
//         int n = s.size();
//         vector<int> dp(n);
//         vector<int> dpPrev(n);
//         for (int i = n - 1; i >= 0; i--) {
//             dp[i] = 1;
//             for (int j = i + 1; j < n; j++) {
//                 if (s[i] == s[j]) {
//                     dp[j] = dpPrev[j - 1] + 2;
//                 } else {
//                     dp[j] = max(dpPrev[j], dp[j - 1]);
//                 }
//             }
//             dp.swap(dpPrev);
//         }
//         return dpPrev[n - 1];
//     }
// };
