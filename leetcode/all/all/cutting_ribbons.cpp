// Ex. [9,7,5], k = 3, start with guess length range 1 to 9
// 1: valid, 2: valid, ..., 5: valid, 6: invalid, 7: invalid...
// Binary search, find last valid value

// Time: O(n log(max(ribbons)))
// Space: O(1)

class Solution {
public:
    int maxLength(vector<int>& ribbons, int k) {
        int low = 1;
        
        int high = 0;
        for (int i = 0; i < ribbons.size(); i++) {
            high = max(high, ribbons[i]);
        }
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int count = 0;
            for (int i = 0; i < ribbons.size(); i++) {
                count += ribbons[i] / mid;
            }
            if (count < k) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return high;
    }
};
