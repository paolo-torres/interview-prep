// Greedy, send the least costly n/2 ppl to city b, rest to a

// Time: O(n log n)
// Space: O(n)

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<vector<int>> diffs;
        for (int i = 0; i < costs.size(); i++) {
            int city1 = costs[i][0];
            int city2 = costs[i][1];
            diffs.push_back({city2 - city1, city1, city2});
        }
        sort(diffs.begin(), diffs.end());
        
        int n = diffs.size();
        int result = 0;
        
        for (int i = 0; i < n; i++) {
            if (i < n / 2) {
                result += diffs[i][2];
            } else {
                result += diffs[i][1];
            }
        }
        
        return result;
    }
};
