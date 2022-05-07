/*
    Given array of coins & an amount, return # of combos that make up this amount
    Ex. amount = 5, coins = [1,2,5] -> 4 (5, 2+2+1, 2+1+1+1, 1+1+1+1+1)

    DFS + memo, 2 choices: either try coin & stay at idx, or don't try & proceed

    Time: O(m x n) -> m = # of coins, n = amount
    Space: O(m x n) -> optimize to O(n)
*/

// class Solution {
// public:
//     int change(int amount, vector<int>& coins) {
//         return dfs(amount, coins, 0, 0);
//     }
// private:
//     // {(index, sum) -> # of combos that make up this amount}
//     map<pair<int, int>, int> dp;
//     int dfs(int amount, vector<int>& coins, int i, int sum) {
//         if (sum == amount) {
//             return 1;
//         }
//         if (sum > amount) {
//             return 0;
//         }
//         if (i == coins.size()) {
//             return 0;
//         }
//         if (dp.find({i, sum}) != dp.end()) {
//             return dp[{i, sum}];
//         }
//         dp[{i, sum}] = dfs(amount, coins, i, sum + coins[i])
//                      + dfs(amount, coins, i + 1, sum);  
//         return dp[{i, sum}];
//     }
// };

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1);
        dp[0] = 1;
        for (int i = 0; i < coins.size(); i++) {
            for (int j = coins[i]; j < amount + 1; j++) {
                dp[j] += dp[j - coins[i]];
            }
        }
        return dp[amount];
    }
};
