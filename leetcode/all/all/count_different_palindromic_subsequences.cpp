/*
    Given string, return # of diff palindromic subsequences
    Ex. s = "bccb" -> 6 ['b','c','bb','cc','bcb','bccb']

    DFS + memo, 2 pointers & count palindromes, 

    Time: O(n^2)
    Space: O(n^2)
*/

class Solution {
public:
    int countPalindromicSubsequences(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        return dfs(s, dp, 0, s.size() - 1);
    }
private:
    int dfs(string& s, vector<vector<int>>& dp, int i, int j) {
        if (i > j) {
            return 0;
        }
        if (i == j) {
            return 1;
        }
        if (dp[i][j] != 0) {
            return dp[i][j];
        }
        
        int count = 0;
        
        if (s[i] == s[j]) {
            // a...a, add 2 ends to every inner palindrome
            count = 2 * dfs(s, dp, i + 1, j - 1);
            
            int left = i + 1;
            int right = j - 1;
            // avoid duplicates
            while (left <= right && s[left] != s[i]) {
                left++;
            }
            while (left <= right && s[right] != s[i]) {
                right--;
            }
            
            if (left < right) {
                // a...a...a...a
                // don't add 2 ends to palindromes between inner
                count -= dfs(s, dp, left + 1, right - 1);
            } else if (left == right) {
                // a...a...a, add aa
                count++;
            } else {
                // a...a, add (a, aa)
                count += 2;
            }
        } else {
            count = dfs(s, dp, i + 1, j) + dfs(s, dp, i, j - 1) - dfs(s, dp, i + 1, j - 1);
        }
        
        dp[i][j] = count >= 0 ? count % 1000000007 : count + 1000000007;
        return dp[i][j];
    }
};
