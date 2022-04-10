// DFS + memoization, track must win/must lose states
// Can use DP -> if dp[i - k * k] = false, can make other lose game

// Time: O(n x sqrt(n))
// Space: O(n)

class Solution {
public:
    bool winnerSquareGame(int n) {
        unordered_map<int, bool> cache;
        cache[0] = false;
        return dfs(cache, n);
    }
private:
    bool dfs(unordered_map<int, bool>& cache, int stonesRemaining) {
        if (cache.find(stonesRemaining) != cache.end()) {
            return cache[stonesRemaining];
        }
        
        int stones = (int) sqrt(stonesRemaining);
        
        for (int i = 1; i <= stones; i++) {
            // if there's a state to make opponent lose next round
            // then curr player will win
            if (!dfs(cache, stonesRemaining - i * i)) {
                cache[stonesRemaining] = true;
                return true;
            }
        }
        
        cache[stonesRemaining] = false;
        return false;
    }
};

// class Solution {
// public:
//     bool winnerSquareGame(int n) {
//         vector<bool> dp(n + 1, false);
//         for (int i = 1; i <= n; i++) {
//             for (int k = 1; k * k <= i; k++) {
//                 if (dp[i - k * k] == false) {
//                     dp[i] = true;
//                     break;
//                 }
//             }
//         }
//         return dp[n];
//     }
// };
