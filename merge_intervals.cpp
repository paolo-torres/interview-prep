class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() < 2) {
            return intervals;
        }
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            return a[0] < b[0];
        });
        vector<vector<int>> result;
        int i = 0;
        while (i < intervals.size() - 1) {
            if (intervals[i][1] >= intervals[i+1][0]) {
                intervals[i+1][0] = intervals[i][0];
                intervals[i+1][1] = max(intervals[i][1], intervals[i+1][1]);
            } else {
                result.push_back(intervals[i]);
            }
            i++;
        }
        result.push_back(intervals[i]);
        return result;
    }
};
