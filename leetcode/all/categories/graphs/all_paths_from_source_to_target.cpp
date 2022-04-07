class Solution {
private:
    void findPaths(vector<vector<int>>& graph, vector<int>& path, int cur, vector<vector<int>>& result) {
        path.push_back(cur);
        if (cur == graph.size() - 1) {
            result.push_back(path);
        } else {
            for (int i = 0; i < graph[cur].size(); i++) {
                findPaths(graph, path, graph[cur][i], result);
            }
        }
        path.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        vector<vector<int>> result;
        findPaths(graph, path, 0, result);
        return result;
    }
};
