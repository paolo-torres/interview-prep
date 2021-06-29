// Time: O(n)
// Space: O(1)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currMax = nums[0];
        int currMin = nums[0];
        int result = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0) {
                swap(currMax, currMin);
            }
            
            currMax = max(currMax * nums[i], nums[i]);
            currMin = min(currMin * nums[i], nums[i]);
            
            result = max(result, currMax);
        }
        
        return result;
    }
};
