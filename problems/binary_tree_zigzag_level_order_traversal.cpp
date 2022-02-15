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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        
        if (root == NULL) {
            return result;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        
        while (!q.empty()) {
            int count = q.size();
            vector<int> curr(count);
            
            for (int i = 0; i < count; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                if (level % 2 == 0) {
                    curr[i] = node->val;
                } else {
                    curr[count - i - 1] = node->val;
                }
                
                if (node->left != NULL) {
                    q.push(node->left);
                }
                if (node->right != NULL) {
                    q.push(node->right);
                }
            }
            
            level++;
            result.push_back(curr);
        }
        
        return result;
    }
};
