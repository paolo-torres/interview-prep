class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        vector<int> dp(nums.begin(), nums.end());
        dp[0] = 1;
        int result = 1;
        for (int i = 1; i < dp.size(); i++) {
            int temp = 0;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    temp = max(temp, dp[j]);
                }
            }
            dp[i] = temp + 1;
            result = max(result, dp[i]);
        }
        return result;
    }
};
