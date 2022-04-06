// BFS traversal, hash map {col, list of nodes}, track min/max col

// Time: O(n)
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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL) {
            return result;
        }
        
        unordered_map<int, vector<int>> m;
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        
        int minCol = 0;
        int maxCol = 0;
        
        while (!q.empty()) {
            TreeNode* node = q.front().first;
            int col = q.front().second;
            q.pop();
            
            m[col].push_back(node->val);
            
            if (node->left != NULL) {
                q.push({node->left, col - 1});
                minCol = min(minCol, col - 1);
            }
            if (node->right != NULL) {
                q.push({node->right, col + 1});
                maxCol = max(maxCol, col + 1);
            }
        }
        
        for (int i = minCol; i <= maxCol; i++) {
            result.push_back(m[i]);
        }
        
        return result;
    }
};
