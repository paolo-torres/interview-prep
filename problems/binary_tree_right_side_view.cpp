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
private:
    void traverse(TreeNode* root, vector<int>& result, int level) {
        if (root == NULL) {
            return;
        }
        if (level > result.size()) {
            result.push_back(root->val);
        }
        traverse(root->right, result, level + 1);
        traverse(root->left, result, level + 1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        traverse(root, result, 1);
        return result;
    }
};
