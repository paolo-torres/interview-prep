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
    int kthSmallest(TreeNode* root, int k) {
        int result = 0;
        kTraverse(root, k, result);
        return result;
    }
private:
    void kTraverse(TreeNode* root, int& k, int& result) {
        if (root == NULL || k == 0) {
            return;
        }
        
        kTraverse(root->left, k, result);
        
        k--;
        if (k == 0) {
            result = root->val;
            return;
        }
        
        kTraverse(root->right, k, result);
    }
};
