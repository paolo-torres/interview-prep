class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        if (nums.empty()) {
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (target < nums[mid]) {
                high = mid - 1;
            } else if (target > nums[mid]) {
                low = mid + 1;
            } else {
                low = mid;
                while (nums[low] == nums[mid]
                    && low != 0) {
                    low--;
                }
                if (nums[low] != nums[mid]) {
                    low++;
                }
                high = mid;
                while (nums[high] == nums[mid]
                    && high != nums.size() - 1) {
                    high++;
                }
                if (nums[high] != nums[mid]) {
                    high--;
                }
                result.push_back(low);
                result.push_back(high);
                return result;
            }
        }
        result.push_back(-1);
        result.push_back(-1);
        return result;
    }
};
