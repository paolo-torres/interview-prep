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
    bool symmetric(TreeNode* leftRoot, TreeNode* rightRoot) {
        if (leftRoot == NULL && rightRoot == NULL) {
            return true;
        } else if (leftRoot != NULL && rightRoot == NULL || leftRoot == NULL && rightRoot != NULL) {
            return false;
        }
        if ((leftRoot->val == rightRoot->val) && symmetric(leftRoot->left, rightRoot->right) && symmetric(leftRoot->right, rightRoot->left)) {
            return true;
        } else {
            return false;
        }
    }
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        if (symmetric(root->left, root->right)) {
            return true;
        }
        return false;
    }
};
