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
    void traverse(TreeNode* root, vector<vector<int>>& result, int level) {
        if (root == NULL) {
            return;
        }
        if (level == result.size()) {
            result.push_back(vector<int>());
        }
        result[level].push_back(root->val);
        traverse(root->left, result, level + 1);
        traverse(root->right, result, level + 1);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        traverse(root, result, 0);
        return result;
    }
};
