// Time: O(n)
// Space: O(1)

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0;
        int j = 0;
        
        int curr = 0;
        int result = INT_MAX;
        
        while (j < nums.size()) {
            curr += nums[j];
            j++;
            while (curr >= target) {
                result = min(result, j - i);
                curr -= nums[i];
                i++;
            }
        }
        
        if (result == INT_MAX) {
            return 0;
        }
        return result;
    }
};
