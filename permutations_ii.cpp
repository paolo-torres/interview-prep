class Solution {
private:
    void permutations(vector<int> nums, vector<vector<int>>& result, int pos) {
        if (pos == nums.size() - 1) {
            result.push_back(nums);
            return;
        }
        for (int i = pos; i < nums.size(); i++) {
            if (i != pos && nums[i] == nums[pos]) {
                continue;
            }
            swap(nums[pos], nums[i]);
            permutations(nums, result, pos + 1);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        permutations(nums, result, 0);
        return result;
    }
};
