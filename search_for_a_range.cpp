class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result = {-1, -1};
        if (nums.empty()) {
            return result;
        }
        int low = 0;
        int high = nums.size() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (target > nums[mid]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        if (target == nums[low]) {
            result[0] = low;
        }
        low = 0;
        high = nums.size() - 1;
        while (low < high) {
            int mid = low + 1 + (high - low) / 2;
            if (target >= nums[mid]) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        if (target == nums[high]) {
            result[1] = high;
        }
        return result;
    }
};
