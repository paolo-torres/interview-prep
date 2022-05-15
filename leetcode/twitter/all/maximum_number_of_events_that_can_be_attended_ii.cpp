// At each event either: 1) skip, or 2) attend + move to next event where start > end
// Compare profits made from these 2 choices and choose the max

// Time: O(n^2 x k)
// Space: O(n x k)

class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(), events.end());
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        return dfs(events, k, dp, 0, n);
    }
private:
    int dfs(vector<vector<int>>& events, int k, vector<vector<int>>& dp, int pos, int n) {
        if (k == 0 || pos >= n) {
            return 0;
        }
        
        if (dp[pos][k] != -1) {
            return dp[pos][k];
        }
        
        int i = pos + 1;
        while (i < n) {
            if (events[i][0] > events[pos][1]) {
                break;
            }
            i++;
        }
        
        dp[pos][k] = max(dfs(events, k, dp, pos + 1, n), dfs(events, k - 1, dp, i, n) + events[pos][2]);
        return dp[pos][k];
    }
};
