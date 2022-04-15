// Given binary tree where root.val = min(root.left.val, root.right.val), output 2nd min value

// If root value of a subtree = first keep searching, else return since it's min

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
    int findSecondMinimumValue(TreeNode* root) {
        return dfs(root, root->val);
    }
private:
    int dfs(TreeNode* root, int first) {
        if (root == NULL) {
            return -1;
        }
        if (root->val != first) {
            return root->val;
        }
        
        int left = dfs(root->left, first);
        int right = dfs(root->right, first);
        
        // if all nodes of a subtree = root->val
        // there's no 2nd minimum value, return -1
        if (left == -1) {
            return right;
        }
        if (right == -1) {
            return left;
        }
        
        return min(left, right);
    }
};
