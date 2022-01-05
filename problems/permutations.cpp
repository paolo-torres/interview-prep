class Solution {
private:
    void permutations(vector<int>& nums, vector<vector<int>>& result, int pos) {
        if (pos == nums.size() - 1) {
            result.push_back(nums);
            return;
        }
        for (int i = pos; i < nums.size(); i++) {
            swap(nums[i], nums[pos]);
            permutations(nums, result, pos + 1);
            swap(nums[i], nums[pos]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        permutations(nums, result, 0);
        return result;
    }
};
