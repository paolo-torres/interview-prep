// Given s, in 1 step can insert any char at any index, return min steps to make palindrome

// Determine longest palindromic subsequence, then we know how many chars to add (n - LPS)
// Works bc LPS is optimal palindrome, so size - LPS gives minimal chars to add

// Time: O(n^2)
// Space: O(n^2)

class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> memo(n + 1, vector<int>(n + 1));
        return n - longestPalindromeSubseq(s, memo, 0, s.size() - 1);
    }
private:
    int longestPalindromeSubseq(string& s, vector<vector<int>>& memo, int i, int j) {
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
        // if chars match, LPS here is inner LPS + 2
        if (s[i] == s[j]) {
            memo[i][j] = longestPalindromeSubseq(s, memo, i + 1, j - 1) + 2;
            return memo[i][j];
        }
        // if chars don't match, LPS is max of LPS w/ i char or w/ j char
        memo[i][j] = max(longestPalindromeSubseq(s, memo, i + 1, j),
                         longestPalindromeSubseq(s, memo, i, j - 1));
        return memo[i][j];
    }
};

// Can space optimize to O(n) since only use i + 1 and j - 1
// class Solution {
// public:
//     int minInsertions(string s) {
//         int n = s.size();
//         int prev = 0;
//         int temp = 0;
//         vector<int> memo(n);
//         for (int i = n - 2; i >= 0; i--) {
//             prev = 0;
//             for (int j = i; j < n; j++) {
//                 temp = memo[j];
//                 if (s[i] == s[j]) {
//                     memo[j] = prev;
//                 } else {
//                     memo[j] = min(memo[j], memo[j - 1]) + 1;
//                 }
//                 prev = temp;
//             }
//         }
//         return memo[n - 1];
//     }
// };
