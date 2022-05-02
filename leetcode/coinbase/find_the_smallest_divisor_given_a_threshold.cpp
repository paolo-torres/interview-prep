/*
    Given array of nums & a threshold, choose a divisor to divide entire array by it
    Find smallest divisor such that result is <= threshold
    Ex. nums = [1,2,5,9], threshold = 6 -> 5, 1 + 1 + 1 + 2 = 5 <= 6

    Use (n + divisor - 1) / divisor to get ceil of n / divisor
    Binary search: if sum too high incr divisor, else decr divisor

    Time: O(n log m) -> n = # of elements, m = max value in nums
    Space: O(1)
*/

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = 1000000;
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            int sum = 0;
            
            for (int i = 0; i < nums.size(); i++) {
                sum += (nums[i] + mid - 1) / mid;
            }
            
            if (sum > threshold) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        
        return low;
    }
};
