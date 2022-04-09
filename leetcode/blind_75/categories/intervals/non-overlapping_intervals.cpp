// Time: O(n log n)
// Space: O(1)

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 1) {
            return 0;
        }
        
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            return a[0] < b[0];
        });
        
        int result = 0;
        
        int i = 0;
        while (i < n - 1) {
            if (intervals[i][1] > intervals[i+1][0]) {
                if (intervals[i][1] < intervals[i+1][1]) {
                    intervals[i+1] = intervals[i];
                }
                result++;
            }
            i++;
        }
        
        return result;
    }
};
