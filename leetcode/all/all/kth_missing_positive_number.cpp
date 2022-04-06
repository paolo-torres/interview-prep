// Linear -> binary search (# of ints missing up to mid)
// Compare w/ no missing int array: [1,2,3,4,5]
// Ex. [2,3,4,7,11], diff b/w arrays = # of ints missing

// Time: O(log n)
// Space: O(1)

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0;
        int high = arr.size() - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int currMissing = arr[mid] - mid - 1;
            
            if (currMissing < k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return low + k;
    }
};
