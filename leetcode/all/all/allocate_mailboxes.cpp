/*
    Given array of houses & an int k, allocate k mailboxes
    Return min total distance b/w each house & its nearest mailbox

    Allocate each mailbox to k groups of consecutive houses
    Sol'n if can distribute total k mailboxes to n houses in k groups
    Choose minimum cost from all solutions

    Time: O(n^3)
    Space: O(n^2)
*/

class Solution {
public:
    int minDistance(vector<int>& houses, int k) {
        int n = houses.size();
        sort(houses.begin(), houses.end());
        memset(memo, -1, sizeof(memo));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int median = houses[(i + j) / 2];
                for (int m = i; m <= j; m++) {
                    costs[i][j] += abs(median - houses[m]);
                }
            }
        }
        
        return dfs(houses, n, k, 0);
    }
private:
    // max distance = n x MAX_POS = 100 x 10^4 = 10^6
    const int INF = 100 * 10000;
    int costs[100][100];
    int memo[100][100];
    
    int dfs(vector<int>& houses, int n, int k, int i) {
        if (k == 0 && i == n) {
            return 0;
        }
        if (k == 0 || i == n) {
            return INF;
        }
        
        if (memo[k][i] != -1) {
            return memo[k][i];
        }
        
        int result = INF;
        for (int j = i; j < n; j++) {
            result = min(result, costs[i][j] + dfs(houses, n, k - 1, j + 1));
        }
        memo[k][i] = result;
        return result;
    }
};
