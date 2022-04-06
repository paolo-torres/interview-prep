// Time: O(V)
// Space: O(V)

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            return {0};
        }
        
        unordered_map<int, unordered_set<int>> m;
        for (int i = 0; i < edges.size(); i++) {
            m[edges[i][0]].insert(edges[i][1]);
            m[edges[i][1]].insert(edges[i][0]);
        }
        
        vector<int> leaves;
        for (auto it = m.begin(); it != m.end(); it++) {
            if (it->second.size() == 1) {
                leaves.push_back(it->first);
            }
        }
        
        while (n > 2) {
            n -= leaves.size();
            vector<int> nextLeaves;
            
            for (int i = 0; i < leaves.size(); i++) {
                auto it = m[leaves[i]].begin();
                int nextNode = *it;
                
                m[leaves[i]].erase(nextNode);
                m[nextNode].erase(leaves[i]);
                
                if (m[nextNode].size() == 1) {
                    nextLeaves.push_back(nextNode);
                }
            }
            
            leaves = nextLeaves;
        }
        
        return leaves;
    }
};
