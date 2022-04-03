// Linear scan O(n) -> modified binary search O(log n)
// Compare mid to right, move accordingly if rising or falling

// Time: O(log n)
// Space: O(1)

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > nums[mid + 1]) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        
        return low;
    }
};
