// Time: O(n log n)
// Space: O(1)

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() < 2) {
            return 0;
        }
        
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            return a[0] < b[0];
        });
        
        int result = 0;
        
        for (int i = 0; i < intervals.size() - 1; i++) {
            if (intervals[i][1] > intervals[i+1][0]) {
                intervals[i+1][0] = intervals[i][0];
                intervals[i+1][1] = min(intervals[i][1], intervals[i+1][1]);
                result++;
            }
        }
        
        return result;
    }
};
