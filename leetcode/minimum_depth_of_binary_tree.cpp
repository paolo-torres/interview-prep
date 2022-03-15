// Time: O(n)
// Space: O(h)

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
    int minDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        
        int curr = 1;
        int result = INT_MAX;
        
        findDepth(root, curr, result);
        return result;
    }
private:
    void findDepth(TreeNode* root, int curr, int& result) {
        if (root == NULL) {
            return;
        }
        if (root->left == NULL && root->right == NULL) {
            result = min(result, curr);
        }
        findDepth(root->left, curr + 1, result);
        findDepth(root->right, curr + 1, result);
    }
};
