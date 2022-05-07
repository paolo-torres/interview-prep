/*
    Given sorted nums & a target, return index if found
    If not found, return index where it would be
    Ex. nums = [1,3,5,6], target = 2 -> 1

    Binary search, if not found return low since low > high

    Time: O(log n)
    Space: O(1)
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (target < nums[mid]) {
                high = mid - 1;
            } else if (target > nums[mid]) {
                low = mid + 1;
            } else {
                return mid;
            }
        }
        
        return low;
    }
};
