// https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/discuss/402945/C%2B%2B-with-picture-generic-topological-sort

class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        vector<vector<int>> graph(n + m);
        vector<int> degree(n + m, 0);
        
        for (int i = 0; i < group.size(); i++) {
            if (group[i] == -1) {
                continue;
            }
            graph[n + group[i]].push_back(i);
            degree[i]++;
        }
        
        for (int i = 0; i < beforeItems.size(); i++) {
            for (int j = 0; j < beforeItems[i].size(); j++) {
                int item = beforeItems[i][j];
                
                int a = n + group[item];
                if (group[item] == -1) {
                    a = item;
                }
                
                int b = n + group[i];
                if (group[i] == -1) {
                    b = i;
                }
                
                if (a == b) {
                    graph[item].push_back(i);
                    degree[i]++;
                } else {
                    graph[a].push_back(b);
                    degree[b]++;
                }
            }
        }
        
        vector<int> result;
        
        for (int i = 0; i < n + m; i++) {
            if (degree[i] == 0) {
                dfs(n, graph, degree, i, result);
            }
        }
        
        if (result.size() == n) {
            return result;
        }
        return {};
    }
private:
    void dfs(int n, vector<vector<int>>& graph, vector<int>& degree, int curr, vector<int>& result) {
        if (curr < n) {
            result.push_back(curr);
        }
        degree[curr] = -1;
        
        for (int i = 0; i < graph[curr].size(); i++) {
            int next = graph[curr][i];
            degree[next]--;
            
            if (degree[next] == 0) {
                dfs(n, graph, degree, next, result);
            }
        }
    }
};
