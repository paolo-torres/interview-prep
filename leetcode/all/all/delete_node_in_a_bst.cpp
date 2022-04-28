/*
    Given a root node of a BST & a key, delete the node with the given key & return the root
    Ex. root = [5,3,6,2,4,null,7], key = 3 -> [5,4,6,2,null,null,7]

    3 cases: 1) leaf, easy, 2) has right, replace w/ successor, 3) has left, predecessor

    Time: O(log n)
    Space: O(log n)
*/

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) {
            return NULL;
        }
        if (key < root->val) {
            // delete from left subtree
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            // delete from right subtree
            root->right = deleteNode(root->right, key);
        } else {
            // delete current node
            if (root->left == NULL && root->right == NULL) {
                // node is a leaf
                root = NULL;
            } else if (root->right != NULL) {
                // node is not a leaf but has right child
                root->val = successor(root);
                root->right = deleteNode(root->right, root->val);
            } else {
                // node is not a leaf, has no right child, but has left child
                root->val = predecessor(root);
                root->left = deleteNode(root->left, root->val);
            }
        }
        return root;
    }
private:
    // 1 step right then as far left as possible
    int successor(TreeNode* root) {
        root = root->right;
        while (root->left != NULL) {
            root = root->left;
        }
        return root->val;
    }
    
    // 1 step left then as far right as possible
    int predecessor(TreeNode* root) {
        root = root->left;
        while (root->right != NULL) {
            root = root->right;
        }
        return root->val;
    }
};
