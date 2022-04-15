// Given int array & k, return true if possible to divide array into k non-empty subsets w/ equal sums
// Ex. nums = [4,3,2,3,5,2,1], k = 4 -> output = true, 4 subsets (5), (1, 4), (2, 3), (2, 3) w/ sum 5

// Determine target, backtracking, try diff sums, maintain visited for dupes, sort + end early to optimize

// Time: O(k x 2^n)
// Space: O(n)

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int target = 0;
        for (int i = 0; i < nums.size(); i++) {
            target += nums[i];
        }
        if (target % k != 0) {
            return false;
        }
        target /= k;
        
        sort(nums.begin(), nums.end(), greater<int>());
        vector<bool> visited(nums.size(), false);
        
        return canPartition(nums, k, 0, 0, target, visited);
    }
private:
    bool canPartition(vector<int>& nums, int k, int start, int sum, int target, vector<bool>& visited) {
        if (k == 0) {
            return true;
        }
        if (sum == target) {
            return canPartition(nums, k - 1, 0, 0, target, visited);
        }
        for (int i = start; i < nums.size(); i++) {
            if (visited[i] || sum + nums[i] > target) {
                continue;
            }
            if (i > 0 && !visited[i - 1] && nums[i] == nums[i - 1]) {
                continue;
            }
            visited[i] = true;
            if (canPartition(nums, k, i + 1, sum + nums[i], target, visited)) {
                return true;
            }
            visited[i] = false;
        }
        return false;
    }
};
