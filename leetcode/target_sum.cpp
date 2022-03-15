// https://leetcode.com/problems/target-sum/discuss/97334/Java-(15-ms)-C%2B%2B-(3-ms)-O(ns)-iterative-DP-solution-using-subset-sum-with-explanation

// Time: O(n x target)
// Space: O(target)

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        
        if (sum < target || sum + target < 0 || (sum + target) % 2 > 0) {
            return 0;
        }
        
        return subsetSum(nums, (sum + target) / 2);
    }
private:
    int subsetSum(vector<int>& nums, int sum) {
        vector<int> dp(sum + 1, 0);
        dp[0] = 1;
        
        for (int i = 0; i < nums.size(); i++) {
            for (int j = sum; j >= nums[i]; j--) {
                dp[j] = dp[j] + dp[j - nums[i]];
            }
        }
        
        return dp[sum];
    }
};
