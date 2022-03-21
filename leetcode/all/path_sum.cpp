// Time: O(n)
// Space: O(n)

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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL) {
            return false;
        }
        int currSum = 0;
        return hasSum(root, currSum, targetSum);
    }
private:
    bool hasSum(TreeNode* root, int currSum, int targetSum) {
        if (root == NULL) {
            return false;
        }
        currSum += root->val;
        if (root->left == NULL && root->right == NULL) {
            if (currSum == targetSum) {
                return true;
            }
        }
        return hasSum(root->left, currSum, targetSum) || hasSum(root->right, currSum, targetSum);
    }
};
