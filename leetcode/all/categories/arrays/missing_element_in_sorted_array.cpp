// Find leftmost such that # of missing nums up to here is <= k

// Time: O(log n)
// Space: O(1)

class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int low = 0;
        int high = nums.size() - 1;
        int currMissing = 0;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            currMissing = nums[mid] - nums[0] - mid;
            
            if (currMissing < k) {
                // # of missing nums from nums[0] to mid < k
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        if (currMissing >= k) {
            // missing element is to the left of nums[low]
            // minus 1 b/c we don't include nums[low]
            return nums[low] - 1 - (currMissing - k);
        }
        return nums[high] + (k - currMissing);
    }
};
