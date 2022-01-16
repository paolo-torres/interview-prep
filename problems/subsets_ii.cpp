// Time: O(n x 2^n)
// Space: O(n)

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
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
        
        while (index < nums.size() - 1 && nums[index] == nums[index + 1]) {
            index++;
        }
        findSubsets(nums, index + 1, curr, result);
    }
};
