/*
    Given points, an angle & locations, return max # of points that can be seen
    Ex. points = [[2,1],[2,2],[3,3]], angle = 90, location = [1,1] -> 3

    Get angles b/w each pt & location, duplicate array since circular
    Use a sliding window to find max # of points that fit within given angle

    Time: O(n log n)
    Space: O(n)
*/

class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        vector<double> v;
        
        int common = 0;
        for (int i = 0; i < points.size(); i++) {
            int x = points[i][0] - location[0];
            int y = points[i][1] - location[1];
            // point same as location
            if (x == 0 && y == 0) {
                common++;
            } else {
                double a = getAngle(x, y);
                if (a < 0) {
                    a += 360;
                }
                v.push_back(a);
            }
        }

        sort(v.begin(), v.end());
        vector<double> angles = v;
        angles.insert(angles.end(), v.begin(), v.end());
        for (int i = v.size(); i < angles.size(); i++) {
            angles[i] += 360;
        }
        
        int result = 0;
        for (int i = 0, j = 0; i < angles.size(); i++) {
            while (j < angles.size() && angles[j] - angles[i] <= angle) {
                j++;
            }
            result = max(result, j - i);
        }
        return result + common;
    }
private:
    double getAngle(int x, int y) {
        return atan2(y, x) * 180 / M_PI;
    }
};
