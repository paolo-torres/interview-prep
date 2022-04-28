/*
    Graph is bipartite if nodes can be partitioned into 2 independent sets
    such that every edge connects a node in set A w/ a node in set B
    Return true if and only if the input graph is bipartite

    Use 2 colors, DFS, for a node, all neighbors should be the other color

    Time: O(V + E)
    Space: O(V)
*/

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n);
        
        queue<int> q;
        
        for (int i = 0; i < n; i++) {
            // skip already colored (visited) nodes
            if (colors[i] != 0) {
                continue;
            }
            q.push(i);
            // blue = 1, red = -1
            colors[i] = 1;
            
            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                
                for (int j = 0; j < graph[curr].size(); j++) {
                    int next = graph[curr][j];
                    if (colors[next] == 0) {
                        // if neighbor node hasn't been colored (visited)
                        // color it with the other color
                        colors[next] = -colors[curr];
                        q.push(next);
                    } else if (colors[next] == colors[curr]) {
                        // if neighbor node has same color, return false
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
};
