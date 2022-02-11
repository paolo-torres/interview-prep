// Time: O(log (n - k) + k)
// Space: O(1)

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int low = 0;
        int high = arr.size() - k;
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (x > ((double) arr[mid] + arr[mid + k]) / 2) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        
        vector<int> result;
        for (int i = low; i < low + k; i++) {
            result.push_back(arr[i]);
        }
        return result;
    }
};
