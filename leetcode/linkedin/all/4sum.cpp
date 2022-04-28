/*
    Given array of nums, return array of all unique quadruplets that add to target
    Ex. nums = [1,0,-1,0,-2,2], target = 0 -> [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

    2 pointers, generalize to kSum, maintain (k - 2) pointers & perform two sum

    Time: O(n^(k - 1)) -> k >= 2
    Space: O(n) -> ignoring output
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        kSum(nums, target, 4);
        return result;
    }
private:
    vector<vector<int>> result;
    
    void kSum(vector<int>& nums, int target, int k) {
        vector<int> curr;
        dfs(nums, target, k, curr, 0, nums.size() - 1);
    }
    
    void dfs(vector<int>& nums, int target, int k, vector<int>& curr, int i, int j) {
        // two sum
        if (k == 2) {
            while (i < j) {
                if (nums[i] + nums[j] < target) {
                    // sum too low, increase
                    i++;
                } else if (nums[i] + nums[j] > target) {
                    // sum too high, decrease
                    j--;
                } else {
                    curr.push_back(nums[i]);
                    curr.push_back(nums[j]);
                    result.push_back(curr);
                    curr.pop_back();
                    curr.pop_back();
                    // skip duplicates
                    while (i + 1 < j && nums[i] == nums[i + 1]) {
                        i++;
                    }
                    i++;
                    j--;
                }
            }
        }
        
        while (i < j) {
            curr.push_back(nums[i]);
            dfs(nums, target - nums[i], k - 1, curr, i + 1, j);
            curr.pop_back();
            // skip duplicates
            while (i + 1 < j && nums[i] == nums[i + 1]) {
                i++;
            }
            i++;
        }
    }
};
