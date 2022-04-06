// Time: O(n)
// Space: O(1)

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            int index = abs(nums[i]) - 1;
            nums[index] = nums[index] > 0 ? -nums[index] : nums[index];
        }
        
        vector<int> result;
        
        for (int i = 1; i <= n; i++) {
            if (nums[i-1] > 0) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};
