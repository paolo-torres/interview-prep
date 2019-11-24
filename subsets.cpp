class Solution {
private:
    vector<int> temp;
    vector<vector<int>> result;
    void findSubsets(vector<int>& nums, int index) {
        if (index == nums.size()) {
            result.push_back(temp);
            return;
        }
        temp.push_back(nums[index]);
        findSubsets(nums, index + 1);
        temp.pop_back();
        findSubsets(nums, index + 1);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int index = 0;
        findSubsets(nums, index);
        return result;
    }
};
