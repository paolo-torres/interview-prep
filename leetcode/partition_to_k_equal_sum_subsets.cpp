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
