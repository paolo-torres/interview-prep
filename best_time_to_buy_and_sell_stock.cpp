class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) {
            return 0;
        }
        int minValue = prices[0];
        int maxDiff = 0;
        for (int i = 1; i < prices.size(); i++) {
            minValue = min(minValue, prices[i]);
            maxDiff = max(maxDiff, prices[i] - minValue);
        }
        return maxDiff;
    }
};
