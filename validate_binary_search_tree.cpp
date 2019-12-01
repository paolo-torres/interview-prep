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
    bool checkBST(TreeNode* root, TreeNode* &temp) {
        if (root == NULL) {
            return true;
        }
        if (!checkBST(root->left, temp)) {
            return false;
        }
        if (temp != NULL && root->val <= temp->val) {
            return false;
        }
        temp = root;
        if (!checkBST(root->right, temp)) {
            return false;
        }
        return true;
    }
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* temp = NULL;
        return checkBST(root, temp);
    }
};
