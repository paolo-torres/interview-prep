/*
    Mountain: arr[i-...] < arr[i] > arr[i+...], find it
    Ex. arr = [0,1,0] -> 1, arr = [0,2,1,0] -> 1

    Linear scan A[i] >= A[i+1] -> optimize w/ binary search

    Time: O(log n)
    Space:  O(1)
*/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 0;
        int high = arr.size() - 1;
        
        int mid = 0;
        while (low < high) {
            mid = low + (high - low) / 2;
            if (arr[mid] < arr[mid + 1]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        
        return low;
    }
};
