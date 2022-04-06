// Backtracking, generate all combinations, push/pop + index checking to explore new combos

// Time: O(n x 2^n)
// Space: O(n)

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> result;
        findSubsets(nums, 0, curr, result);
        return result;
    }
private:
    void findSubsets(vector<int>& nums, int index, vector<int>& curr, vector<vector<int>>& result) {
        if (index == nums.size()) {
            result.push_back(curr);
            return;
        }
        curr.push_back(nums[index]);
        findSubsets(nums, index + 1, curr, result);
        curr.pop_back();
        findSubsets(nums, index + 1, curr, result);
    }
};
