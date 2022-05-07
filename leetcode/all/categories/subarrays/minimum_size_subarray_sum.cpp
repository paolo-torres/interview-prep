/*
    Given a target & nums array, return min contiguous subarray
    where sum of the subarray is >= target
    Ex. target = 7, nums = [2,3,1,2,4,3] -> 2, [4,3]

    Sliding window, expand while sum < target, contract until valid

    Time: O(n)
    Space: O(1)
*/

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
