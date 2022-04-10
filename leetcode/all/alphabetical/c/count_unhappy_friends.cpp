// x prefers u over y, & u prefers x over v -> both x & u unhappy
// Track positions in hash map to determine unhappiness

// Time: O(n^2)
// Space: O(n)

class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        // position[i][j] -> position of i in list of position j
        unordered_map<int, unordered_map<int, int>> positions;
        unordered_set<int> result;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1; j++) {
                int preference = preferences[i][j];
                positions[preference][i] = j;
            }
        }
        
        for (int i = 0; i < pairs.size() - 1; i++) {
            for (int j = i + 1; j < pairs.size(); j++) {
                int x = pairs[i][0];
                int y = pairs[i][1];
                int u = pairs[j][0];
                int v = pairs[j][1];
                // if x prefers u over y, & u prefers x over v
                checkHappiness(x, y, u, v, positions, result);
                checkHappiness(x, y, v, u, positions, result);
                checkHappiness(y, x, u, v, positions, result);
                checkHappiness(y, x, v, u, positions, result);
            }
        }
        
        return result.size();
    }
private:
    void checkHappiness(int x, int y, int u, int v,
        unordered_map<int, unordered_map<int, int>>& positions, unordered_set<int>& result) {
        if (positions[u][x] < positions[y][x] && positions[x][u] < positions[v][u]) {
            result.insert(x);
            result.insert(u);
        }
    }
};
