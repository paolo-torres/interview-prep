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
    void levels(vector<vector<int>>& result, TreeNode* root, int level) {
        if (root == NULL) {
            return;
        }
        if (level == result.size()) {
            result.push_back(vector<int>());
        }
        result[level].push_back(root->val);
        levels(result, root->left, level + 1);
        levels(result, root->right, level + 1);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        levels(result, root, 0);
        return result;
    }
};
