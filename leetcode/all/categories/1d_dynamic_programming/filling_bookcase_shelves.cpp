// 1. Start placing books 1 by 1, always use a new shelf initially
// 2. Look back at prev books 1 by 1, within width, see how many can fit
// 3. Check if bringing books down reduced height, if so update
// 4. Return last element of DP array

// Time: O(m x n) -> m = max width, n = number of books
// Space: O(m x n)

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n + 1);
        dp[0] = 0;
        
        for (int i = 1; i <= n; i++) {
            int width = books[i - 1][0];
            int height = books[i - 1][1];
            
            // 1.
            dp[i] = dp[i - 1] + height;
            
            // 2.
            for (int j = i - 1; j > 0; j--) {
                if (width + books[j - 1][0] > shelfWidth) {
                    break;
                }
                width += books[j - 1][0];
                height = max(height, books[j - 1][1]);
                // 3.
                dp[i] = min(dp[i], dp[j - 1] + height);
            }
        }
        
        // 4.
        return dp[n];
    }
};
