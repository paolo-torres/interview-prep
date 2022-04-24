/*
    Binary grid, 0 = wall, 1 = empty, clean entire room, robot can: move, turn L/R, clean

    Visit each cell, BFS explore all 4 directions, backtrack if stuck, turn at obstacles

    Time: O(n - m) -> n = number of cells in the room, m = number of obstacles
    Space: O(n - m)
*/

/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
public:
    void cleanRoom(Robot& robot) {
        backtrack(robot, 0, 0, 0);
    }
private:
    vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    unordered_set<string> visited;
    
    void backtrack(Robot& robot, int row, int col, int direction) {
        string key = to_string(row) + ',' + to_string(col);
        visited.insert(key);
        robot.clean();
        
        // explore: 0 = up, 1 = right, 2 = down, and 3 = left
        for (int i = 0; i < 4; i++) {
            // ensure order of dirs is in the same order of exploration
            int newDirection = (direction + i) % 4;
            int newRow = row + dirs[newDirection][0];
            int newCol = col + dirs[newDirection][1];
            
            string key = to_string(newRow) + ',' + to_string(newCol);
            if (visited.find(key) == visited.end() && robot.move()) {
                backtrack(robot, newRow, newCol, newDirection);
                // backtrack the robot if stuck/explore new areas
                goBack(robot);
            }
            
            // turn robot right whenever wall
            robot.turnRight();
        }
    }
    
    void goBack(Robot& robot) {
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
    }
};
