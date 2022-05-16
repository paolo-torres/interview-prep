/*
    2 players playing game where cards laid out in straight line.
    Value of each card ranges from a reasonable [-'ve to +'ve].
    Rules:
        1. Player 1 starts.
        2. Each player has 3 options:
            a. Pick first card
            b. Pick first 2 cards
            c. Pick first 3 cards
        3. Only allowed to pick from left side of deck.
        4. Both players have to play optimally.
    Return maximum sum of cards Player 1 can obtain.
    Ex. cards = [1,2,-3,8] -> 3, Player 1 = 1 + 2, Player 2 = -3 + 8

    DP on max possible score, each time, want to minimize opp. score

    Time: O(n)
    Space: O(n)
*/

#include <stdio.h>

#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int cardGame(vector<int>& cards) {
        if (cards.empty()) {
            return 0;
        }

        int n = cards.size();
        int sum = 0;
        // dp[i] = max possible score Player 1 starting from index i
        vector<int> dp(n + 3);

        for (int i = n - 1; i >= 0; i--) {
            sum += cards[i];
            int curr = INT_MAX;

            for (int j = 1; j <= 3; j++) {
                // take option that minimizes max score for opponent
                curr = min(curr, dp[i + j]);
            }

            // total - minimized max score for opponent
            dp[i] = sum - curr;
        }

        return dp[0];
    }
};

int main() {
    vector<int> cards1 = {1, 2, -3, 8};
    vector<int> cards2 = {1, 1, 1, 1, 100};
    Solution* obj = new Solution();
    cout << obj->cardGame(cards1) << " "
         << obj->cardGame(cards2) << endl;

    return 0;
}
