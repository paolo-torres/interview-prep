// Calculate angles separately from 0 line, handle minute moving hour

// Time: O(1)
// Space: O(1)

class Solution {
public:
    double angleClock(int hour, int minutes) {
        int oneMinAngle = 6;
        int oneHourAngle = 30;
        
        double minuteAngle = minutes * oneMinAngle;
        // hour 12 = angle 0, "+ minutes / 60.0" since minute moves hour
        double hourAngle = (hour % 12 + minutes / 60.0) * oneHourAngle;
        
        double result = abs(hourAngle - minuteAngle);
        if (result > 180) {
            return 360 - result;
        }
        return result;
    }
};
