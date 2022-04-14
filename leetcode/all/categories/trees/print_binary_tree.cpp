// Given root of binary tree, output a string matrix that represents formatted layout of tree

// Preorder traversal, get mid & print at center of subtree, recurse on left/right

// Time: O(n x 2^n)
// Space: O(n x 2^n)

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
    vector<vector<string>> printTree(TreeNode* root) {
        int height = getHeight(root);
        // how many nodes in nth level? n = 1: 2^0, n = 2: 2^1, n = 3: 2^2
        // nth level: 2^(n - 1) = (2^n) - 1 -> if tree has height h, width = (2^h) - 1
        int width = pow(2, height) - 1;
        
        vector<vector<string>> result(height, vector<string>(width));
        dfs(root, 0, 0, width - 1, result);
        
        return result;
    }
private:
    void dfs(TreeNode* node, int row, int i, int j, vector<vector<string>>& result) {
        if (node == NULL) {
            return;
        }
        
        int mid = i + (j - i) / 2;
        result[row][mid] = to_string(node->val);
        
        dfs(node->left, row + 1, i, mid - 1, result);
        dfs(node->right, row + 1, mid + 1, j, result);
    }
    
    int getHeight(TreeNode* node) {
        if (node == NULL) {
            return 0;
        }
        return 1 + max(getHeight(node->left), getHeight(node->right));
    }
};
