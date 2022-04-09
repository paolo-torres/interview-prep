// Divide-and-conquer, base case if converge on a point, else recurse 4

// Time: O(S x log max(m, n)) -> S = max # of ships, m = x-vals, n = y-vals
// Space: O(log max(m, n))

/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */

class Solution {
public:
    int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
        // if coordinates out of bounds or doesn't have any ships, return 0
        if (bottomLeft[0] > topRight[0] || bottomLeft[1] > topRight[1]) {
            return 0;
        }
        if (!sea.hasShips(topRight, bottomLeft)) {
            return 0;
        }
        
        // if rectangle is at a specific point, a ship has been located
        if (bottomLeft[0] == topRight[0] && bottomLeft[1] == topRight[1]) {
            return 1;
        }
        
        // recursively check each of the 4 sub-rectangles for ships
        int xMid = (bottomLeft[0] + topRight[0]) / 2;
        int yMid = (bottomLeft[1] + topRight[1]) / 2;
        
        return countShips(sea, {xMid, yMid}, bottomLeft) // bottom left
            + countShips(sea, {xMid, topRight[1]}, {bottomLeft[0], yMid + 1}) // top left
            + countShips(sea, topRight, {xMid + 1, yMid + 1}) // top right
            + countShips(sea, {topRight[0], yMid}, {xMid + 1, bottomLeft[1]}); // bottom right
    }
};
