/*
    Given cost array, ith step is cost[i], can climb 1 or 2 steps
    Return min cost to reach top floor, can start at index 0 or 1
    Ex. cost = [10,15,20] -> 15, start at idx 1, pay 15, climb 2

    Recursion w/ memoization -> DP, min cost to reach 1/2 steps below curr step
    Recurrence relation: minCost[i] = min(minCost[i-1] + cost[i-1], minCost[i-2] + cost[i-2])

    Time: O(n)
    Space: O(1)
*/

// class Solution {
// public:
//     int minCostClimbingStairs(vector<int>& cost) {
//         return dfs(cost.size(), cost);
//     }
// private:
//     unordered_map<int, int> memo;
//     int dfs(int i, vector<int>& cost) {
//         if (i <= 1) {
//             return 0;
//         }
//         if (memo.find(i) != memo.end()) {
//             return memo[i];
//         }
//         int downOne = cost[i - 1] + dfs(i - 1, cost);
//         int downTwo = cost[i - 2] + dfs(i - 2, cost);
//         memo[i] = min(downOne, downTwo);
//         return memo[i];
//     }
// };

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int downOne = 0;
        int downTwo = 0;
        
        for (int i = 2; i <= cost.size(); i++) {
            int temp = downOne;
            downOne = min(downOne + cost[i - 1], downTwo + cost[i - 2]);
            downTwo = temp;
        }
        
        return downOne;
    }
};
