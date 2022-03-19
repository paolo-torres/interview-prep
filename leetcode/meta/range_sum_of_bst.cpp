// Traverse using BST property, add if value is within range

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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int result = 0;
        traverse(root, low, high, result);
        return result;
    }
private:
    void traverse(TreeNode* root, int low, int high, int& result) {
        if (root == NULL) {
            return;
        }
        
        if (low <= root->val && root->val <= high) {
            result += root->val;
        }
        if (low < root->val) {
            traverse(root->left, low, high, result);
        }
        if (root->val < high) {
            traverse(root->right, low, high, result);
        }
    }
};
