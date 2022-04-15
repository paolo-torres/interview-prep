// Given the root of a binary tree, turn the tree upside down and return the new root
// (1) Orig left -> new root, (2) orig root -> new right, (3) orig right -> new left

// Ex. root = [1,2,3,4,5] -> output = [4,5,2,null,null,3,1]
// Draw it out, "comb", 1,2,4 "bone", 3,5 "teeth" -> flip teeth direction

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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (root == NULL || root->left == NULL) {
            return root;
        }
        
        TreeNode* newRoot = upsideDownBinaryTree(root->left);
        
        // left child pointer flip
        root->left->left = root->right;
        // right child pointer flip
        root->left->right = root;
        
        root->left = NULL;
        root->right = NULL;
        
        return newRoot;
    }
};

// class Solution {
// public:
//     TreeNode* upsideDownBinaryTree(TreeNode* root) {
//         TreeNode* curr = root;
//         TreeNode* prev = NULL;
//         TreeNode* temp = NULL;
//         TreeNode* next = NULL;
//         while (curr != NULL) {
//             next = curr->left;
//             curr->left = temp;
//             temp = curr->right;
//             curr->right = prev;
//             prev = curr;
//             curr = next;
//         }
//         return prev;
//     }
// };
