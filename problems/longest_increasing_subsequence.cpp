// Time: O(n^2)
// Space: O(n)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = 1;
        int result = 1;
        for (int i = 1; i < n; i++) {
            int maxValue = 0;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    maxValue = max(maxValue, dp[j]);
                }
            }
            dp[i] = maxValue + 1;
            result = max(result, dp[i]);
        }
        return result;
    }
};
