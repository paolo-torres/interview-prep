// Time: O(n x n!)
// Space: O(n)

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        findPermutations(nums, 0, result);
        return result;
    }
private:
    void findPermutations(vector<int>& nums, int pos, vector<vector<int>>& result) {
        if (pos == nums.size()) {
            result.push_back(nums);
            return;
        }
        for (int i = pos; i < nums.size(); i++) {
            swap(nums[i], nums[pos]);
            findPermutations(nums, pos + 1, result);
            swap(nums[i], nums[pos]);
        }
    }
};
