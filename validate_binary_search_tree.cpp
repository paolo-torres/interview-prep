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
    bool checkBST(TreeNode* root, TreeNode* &prev) {
        if (root == NULL) {
            return true;
        }
        if (!checkBST(root->left, prev)) {
            return false;
        }
        if (prev != NULL && prev->val >= root->val) {
            return false;
        }
        prev = root;
        if (!checkBST(root->right, prev)) {
            return false;
        }
        return true;
    }
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return checkBST(root, prev);
    }
};
