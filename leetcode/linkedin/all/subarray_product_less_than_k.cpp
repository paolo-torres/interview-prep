/*
    Given an array of integers nums & an int k, return # of contiguous subarrays
    where the product of all elements in the subarray is strictly less than k
    Ex. nums = [10,5,2,6], k = 100 -> 8 [10],[5],[2],[6],[10,5],[5,2],[2,6],[5,2,6]

    Sliding window, add to result length of the window b/c captures all subarrays

    Time: O(n)
    Space: O(1)
*/

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
