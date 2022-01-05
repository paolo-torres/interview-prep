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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        
        if (root == NULL) {
            return result;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int count = q.size();
            vector<int> currLevel;
            
            for (int i = 0; i < count; i++) {
                TreeNode* node = q.front();
                q.pop();
                currLevel.push_back(node->val);
                
                if (node->left != NULL) {
                    q.push(node->left);
                }
                
                if (node->right != NULL) {
                    q.push(node->right);
                }
            }
            
            result.push_back(currLevel);
        }
        
        return result;
    }
};
