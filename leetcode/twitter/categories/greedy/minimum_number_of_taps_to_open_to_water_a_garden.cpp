// Store max reachable index at each index
// Then Jump Game II (min jumps from 0 to n)

// Time: O(n^2)
// Space: O(n)

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> arr(n + 1);
        for (int i = 0; i < ranges.size(); i++) {
            if (ranges[i] == 0) {
                continue;
            }
            int left = max(0, i - ranges[i]);
            int right = min(n, i + ranges[i]);
            arr[left] = max(arr[left], right);
        }
        
        int end = 0;
        int reachable = 0;
        
        int i = 0;
        int result = 0;
        
        while (i < n + 1 && end < n) {
            result++;
            while (i < n && i <= end) {
                reachable = max(reachable, arr[i]);
                i++;
            }
            if (end == reachable) {
                return -1;
            }
            end = reachable;
        }
        
        return result;
    }
};
