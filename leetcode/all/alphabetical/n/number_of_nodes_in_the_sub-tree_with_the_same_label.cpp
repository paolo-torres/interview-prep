// Build adj list, avoid duplicate visits, count total for each char
// DFS, count each label & sum, update result

// Time: O(n)
// Space: O(n)

class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int> count(26);
        vector<int> result(n);
        dfs(labels, 0, adj, count, result);
        return result;
    }
private:
    void dfs(string& labels, int index, vector<vector<int>>& adj, vector<int>& count, vector<int>& result) {
        if (result[index] != 0) {
            return;
        }
        result[index] = 1;
        
        vector<int> neighbours = adj[index];
        for (int i = 0; i < neighbours.size(); i++) {
            vector<int> subtree(26);
            dfs(labels, neighbours[i], adj, subtree, result);
            for (int j = 0; j < 26; j++) {
                count[j] += subtree[j];
            }
        }
        
        count[labels[index] - 'a']++;
        result[index] = count[labels[index] - 'a'];
    }
};
