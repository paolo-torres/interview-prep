// Row of n houses, each painted 1 of 3 colors, diff costs, no adj houses same color
// Return min cost to paint all houses

// // Time: O(2^n)
// // Space: O(n)

// class Solution {
// public:
//     int minCost(vector<vector<int>>& costs) {
//         return min(cost(costs, 0, 0), min(cost(costs, 0, 1), cost(costs, 0, 2)));
//     }
// private:
//     int cost(vector<vector<int>>& costs, int i, int color) {
//         int total = costs[i][color];
//         if (i == costs.size() - 1) {
//             return total;
//         }
//         if (color == 0) {
//             total += min(cost(costs, i + 1, 1), cost(costs, i + 1, 2));
//         } else if (color == 1) {
//             total += min(cost(costs, i + 1, 0), cost(costs, i + 1, 2));
//         } else {
//             total += min(cost(costs, i + 1, 0), cost(costs, i + 1, 1));
//         }
//         return total;
//     }
// };

// Brute force recursive -> DP, optimal substructure
// Iterate backwards, cost is itself + min of the others

// Time: O(n)
// Space: O(1)

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        for (int i = costs.size() - 2; i >= 0; i--) {
            costs[i][0] += min(costs[i + 1][1], costs[i + 1][2]);
            costs[i][1] += min(costs[i + 1][0], costs[i + 1][2]);
            costs[i][2] += min(costs[i + 1][0], costs[i + 1][1]);
        }
        
        return min(costs[0][0], min(costs[0][1], costs[0][2]));
    }
};
