// 2 binary searches, slightly diff (biased towards left/right)

// Time: O(log n)
// Space: O(1)

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result = {-1, -1};
        
        if (nums.empty()) {
            return result;
        }
        
        int low = 0;
        int high = nums.size() - 1;
        
        // search for the left one
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        if (nums[low] != target) {
            return result;
        }
        result[0] = low;
        
        // search for the right one
        high = nums.size() - 1;
        while (low < high) {
            // make mid biased to the right
            int mid = low + (high - low + 1) / 2;
            if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid;
            }
        }
        result[1] = high;
        
        return result;
    }
};
