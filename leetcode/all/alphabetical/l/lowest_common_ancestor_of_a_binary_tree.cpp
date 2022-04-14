// Given binary tree, find LCA of 2 given nodes in the tree

// If one NULL the other must be LCA, if both non-NULL parent LCA

// Time: O(n)
// Space: O(n)

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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || root == p || root == q) {
            return root;
        }
        
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        if (left == NULL) {
            return right;
        }
        if (right == NULL) {
            return left;
        }
        
        return root;
    }
};

// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         unordered_map<TreeNode*, TreeNode*> parents;
//         queue<TreeNode*> queue;
//         queue.push(root);
//         while (parents.find(p) == parents.end() || parents.find(q) == parents.end()) {
//             int count = queue.size();
//             for (int i = 0; i < count; i++) {
//                 TreeNode* node = queue.front();
//                 queue.pop();
//                 if (node->left != NULL) {
//                     parents[node->left] = node;
//                     queue.push(node->left);
//                 }
//                 if (node->right != NULL) {
//                     parents[node->right] = node;
//                     queue.push(node->right);
//                 }
//             }
//         }
//         unordered_set<TreeNode*> ancestors;
//         while (p != NULL) {
//             ancestors.insert(p);
//             p = parents[p];
//         }
//         while (q != NULL && ancestors.find(q) == ancestors.end()) {
//             q = parents[q];
//         }
//         return q;
//     }
// };
