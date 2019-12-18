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
    bool checkSymmetric(TreeNode* leftRoot, TreeNode* rightRoot) {
        if (leftRoot == NULL && rightRoot == NULL) {
            return true;
        }
        if (leftRoot == NULL || rightRoot == NULL) {
            return false;
        }
        if (leftRoot->val == rightRoot->val && checkSymmetric(leftRoot->left, rightRoot->right) && checkSymmetric(leftRoot->right, rightRoot->left)) {
            return true;
        }
        return false;
    }
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        return checkSymmetric(root->left, root->right);
    }
};
