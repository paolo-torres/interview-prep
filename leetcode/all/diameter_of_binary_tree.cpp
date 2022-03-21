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
    int diameterOfBinaryTree(TreeNode* root) {
        int result = 0;
        traverse(root, result);
        return result;
    }
private:
    int traverse(TreeNode* root, int& result) {
        if (root == NULL) {
            return 0;
        }
        
        int left = traverse(root->left, result);
        int right = traverse(root->right, result);
        
        result = max(result, left + right);
        return 1 + max(left, right);
    }
};
