// Same as subtracting, making all elements equal to min

// Time: O(n)
// Space: O(1)

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int minValue = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            minValue = min(minValue, nums[i]);
        }
        
        int result = 0;
        
        for (int i = 0; i < n; i++) {
            result += nums[i] - minValue;
        }
        
        return result;
    }
};
