/*
    Given array of coins & an amount, return fewest coins to make that amount
    Ex. coins = [1,2,5], amount = 11 -> 3, $11 = $5 + $5 + $1

    Compute all min counts for amounts up to i, "simulate" use of a coin

    Time: O(m x n) -> m = # of coins, n = amount
    Space: O(n)
*/

// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         if (amount < 1) {
//             return 0;
//         }
//         vector<int> count(amount);
//         return dfs(coins, amount, count);
//     }
// private:
//     int dfs(vector<int>& coins, int remainder, vector<int>& count) {
//         if (remainder < 0) {
//             return -1;
//         }
//         if (remainder == 0) {
//             return 0;
//         }
//         if (count[remainder - 1] != 0) {
//             return count[remainder - 1];
//         }
//         int min = INT_MAX;
//         for (int i = 0; i < coins.size(); i++) {
//             int curr = dfs(coins, remainder - coins[i], count);
//             if (curr >= 0 && curr < min) {
//                 min = 1 + curr;
//             }
//         }
//         count[remainder - 1] = min == INT_MAX ? -1 : min;
//         return count[remainder - 1];
//     }
// };

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        
        for (int i = 1; i < amount + 1; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (i - coins[j] >= 0) {
                    dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
                }
            }
        }
        
        if (dp[amount] == amount + 1) {
            return -1;
        }
        return dp[amount];
    }
};
