// Time: O(n)
// Space: O(1)

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) {
            return 0;
        }
        
        int i = 0;
        int j = 0;
        
        int curr = 1;
        int result = 0;
        
        while (j < nums.size()) {
            curr *= nums[j];
            while (curr >= k) {
                curr /= nums[i];
                i++;
            }
            result += j - i + 1;
            j++;
        }
        
        return result;
    }
};
