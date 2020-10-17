class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        if (costs.empty()) {
            return 0;
        }
        int n = costs.size();
        vector<int> refunds;
        int result = 0;
        for (int i = 0; i < n; i++) {
            result += costs[i][0];
            refunds.push_back(costs[i][1] - costs[i][0]);
        }
        sort(refunds.begin(), refunds.end());
        for (int i = 0; i < n / 2; i++) {
            result += refunds[i];
        }
        return result;
    }
};
