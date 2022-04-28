/*
    Given array after some rotation w/ duplicates, find if target is in nums
    Ex. nums = [2,5,6,0,0,1,2] target = 0 -> true

    Modified binary search, if low <= mid left sorted, else right sorted

    Time: O(log n)
    Space: O(1)
*/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                return true;
            }
            // can't use binary search, so just iterate the pointers
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
            } else if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target <= nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                if (nums[mid] <= target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        
        return false;
    }
};
