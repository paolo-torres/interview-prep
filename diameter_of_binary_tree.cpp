/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    int traverse(TreeNode* root, int& result) {
        if (root == NULL) {
            return 0;
        }
        int left = traverse(root->left, result);
        int right = traverse(root->right, result);
        result = max(result, left + right);
        return max(left, right) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int result = 0;
        traverse(root, result);
        return result;
    }
};
