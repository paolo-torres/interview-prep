// Time: O(n^2)
// Space: O(n)

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> dp(n, {1, 1});
        
        int maxLength = 1;
        int result = 1;
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    if (dp[j].first + 1 == dp[i].first) {
                        dp[i].second += dp[j].second;
                    } else if (dp[j].first + 1 > dp[i].first) {
                        dp[i] = {dp[j].first + 1, dp[j].second};
                    }
                }
            }
            if (maxLength == dp[i].first) {
                result += dp[i].second;
            } else if (maxLength < dp[i].first) {
                maxLength = dp[i].first;
                result = dp[i].second;
            }
        }
        
        return result;
    }
};
