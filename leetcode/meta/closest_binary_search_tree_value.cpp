// Binary search, since BST can cut out half the nodes each time

// Time: O(h) -> O(log n) if balanced
// Space: O(1)

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
    int closestValue(TreeNode* root, double target) {
        double diff = abs(root->val - target);
        int result = root->val;
        
        while (root != NULL) {
            if (abs(root->val - target) < diff) {
                diff = abs(root->val - target);
                result = root->val;
            }
            
            if (target < root->val) {
                root = root->left;
            } else {
                root = root->right;
            }
        }
        
        return result;
    }
};
