// Time: O(n log n)
// Space: O(1)

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const auto& a, const auto& b) {
            return a[0] < b[0];
        });
        
        int result = 0;
        
        int i = 0;
        while (i < points.size() - 1) {
            if (points[i][1] >= points[i+1][0]) {
                points[i+1][0] = max(points[i][0], points[i+1][0]);
                points[i+1][1] = min(points[i][1], points[i+1][1]);
            } else {
                result++;
            }
            i++;
        }
        result++;
        
        return result;
    }
};
