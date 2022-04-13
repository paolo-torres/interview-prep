// If the robot returns to its initial point at some time, there's a cycle
// If the robot is facing north at the end, no cycle, will never reach origin

// Time: O(n)
// Space: O(1)

class Solution {
public:
    bool isRobotBounded(string instructions) {
        // north = 0, east = 1, south = 2, west = 3
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        // initial position at the origin
        int x = 0;
        int y = 0;
        
        // initially facing north
        int index = 0;
        
        for (int i = 0; i < instructions.size(); i++) {
            if (instructions[i] == 'L') {
                // 1 left = 3 right, avoid negative indices
                index = (index + 3) % 4;
            } else if (instructions[i] == 'R') {
                // % 4 to wrap back since only 4 directions
                index = (index + 1) % 4;
            } else {
                x += directions[index][0];
                y += directions[index][1];
            }
        }
        
        // if back to initial position or not facing north, there's a cycle
        if (x == 0 && y == 0 || index != 0) {
            return true;
        }
        return false;
    }
};
