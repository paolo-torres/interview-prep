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
    int maxPathSum(TreeNode* root) {
        int maxPath = INT_MIN;
        pathSum(root, maxPath);
        return maxPath;
    }
private:
    int pathSum(TreeNode* node, int& maxPath) {
        if (node == NULL) {
            return 0;
        }
        
        int left = max(pathSum(node->left, maxPath), 0);
        int right = max(pathSum(node->right, maxPath), 0);
        
        int curPath = node->val + left + right;
        maxPath = max(maxPath, curPath);
        
        return node->val + max(left, right);
    }
};
