// BFS + LCA, find deepest leftmost & rightmost nodes, then find LCA

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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (root->left == NULL && root->right == NULL) {
            return root;
        }
        
        TreeNode* leftMost = NULL;
        TreeNode* rightMost = NULL;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int count = q.size();
            
            for (int i = 0; i < count; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                if (i == 0) {
                    leftMost = node;
                }
                if (i == count - 1) {
                    rightMost = node;
                }
                
                if (node->left != NULL) {
                    q.push(node->left);
                }
                if (node->right != NULL) {
                    q.push(node->right);
                }
            }
        }
        
        return lca(root, leftMost, rightMost);
    }
private:
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || root == p || root == q) {
            return root;
        }
        
        TreeNode* left = lca(root->left, p, q);
        TreeNode* right = lca(root->right, p, q);
        
        if (left == NULL) {
            return right;
        }
        if (right == NULL) {
            return left;
        }
        
        return root;
    }
};
