// DFS + backtracking + graph, base case curr index, else explore nodes that can be visited

// Time: O(n x 2^n) -> n = # of nodes, 2^n = backtracking either pick or don't pick node
// Space: O(n x 2^n) -> n from recursive call stack, 2^n from storing paths

class Solution {
private:
    void dfs(vector<vector<int>>& graph, int curr, vector<int>& path, vector<vector<int>>& result) {
        if (curr == graph.size() - 1) {
            result.push_back(path);
            return;
        }
        
        vector<int> node = graph[curr];
        // explore neighbor nodes
        for (int i = 0; i < node.size(); i++) {
            // mark choice before backtracking
            path.push_back(node[i]);
            dfs(graph, node[i], path, result);
            // remove previous check to try next
            path.pop_back();
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        // start from the source (node 0)
        path.push_back(0);
        
        vector<vector<int>> result;
        dfs(graph, 0, path, result);
        
        return result;
    }
};
