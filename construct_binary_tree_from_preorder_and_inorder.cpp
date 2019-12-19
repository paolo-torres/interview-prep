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
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[0]);
        int i = 0;
        for (int index = 0; index < inorder.size(); index++) {
            if (inorder[index] == preorder[0]) {
                i = index;
                break;
            }
        }
        vector<int> preorderLeft(preorder.begin() + 1, preorder.begin() + 1 + i);
        vector<int> preorderRight(preorder.begin() + 1 + i, preorder.end());
        vector<int> inorderLeft(inorder.begin(), inorder.begin() + i);
        vector<int> inorderRight(inorder.begin() + i + 1, inorder.end());
        root->left = buildTree(preorderLeft, inorderLeft);
        root->right = buildTree(preorderRight, inorderRight);
        return root;
    }
};
