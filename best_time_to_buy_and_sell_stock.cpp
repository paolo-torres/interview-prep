class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) {
            return 0;
        }
        int minVal = prices[0];
        int maxDiff = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < minVal) {
                minVal = prices[i];
            }
            if (prices[i] - minVal > maxDiff) {
                maxDiff = prices[i] - minVal;
            }
        }
        return maxDiff;
    }
};
