class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() < 2) {
            return 0;
        }
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            return a[0] < b[0];
        });
        int last = 0;
        int result = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[last][1] <= intervals[i][0]) {
                last = i;
            } else {
                result++;
                if (intervals[last][1] > intervals[i][1]) {
                    last = i;
                }
            }
        }
        return result;
    }
};
