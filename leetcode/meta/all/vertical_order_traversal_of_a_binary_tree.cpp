// BFS traversal, map {col, map {row, set of nodes}}, preserve ordering

// Time: O(n log n)
// Space: O(n)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> m;
        
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        
        while (!q.empty()) {
            TreeNode* node = q.front().first;
            int col = q.front().second.first;
            int row = q.front().second.second;
            q.pop();
            
            m[col][row].insert(node->val);
            
            if (node->left != NULL) {
                q.push({node->left, {col - 1, row + 1}});
            }
            if (node->right != NULL) {
                q.push({node->right, {col + 1, row + 1}});
            }
        }
        
        vector<vector<int>> result;
        
        for (auto col = m.begin(); col != m.end(); col++) {
            vector<int> curr;
            for (auto row = col->second.begin(); row != col->second.end(); row++) {
                curr.insert(curr.end(), row->second.begin(), row->second.end());
            }
            result.push_back(curr);
        }
        
        return result;
    }
};
