class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> result(amount + 1, amount + 1);
        result[0] = 0;
        for (int i = 1; i < result.size(); i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (i >= coins[j]) {
                    result[i] = min(result[i], result[i-coins[j]] + 1);
                }
            }
        }
        if (result[amount] <= amount) {
            return result[amount];
        } else {
            return -1;
        }
    }
};
