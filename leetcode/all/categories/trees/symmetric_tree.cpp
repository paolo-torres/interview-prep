/*
    Given root of a binary tree, check if it is a mirror of itself (symmetric around center)
    Ex. root = [1,2,2,3,4,4,3] -> true

    Symmetric if left subtree is a mirror of right: roots same value, right subtree = left

    Time: O(n)
    Space: O(n)
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

// class Solution {
// public:
//     bool isSymmetric(TreeNode* root) {
//         queue<TreeNode*> q;
//         q.push(root);
//         q.push(root);
//         while (!q.empty()) {
//             TreeNode* t1 = q.front();
//             q.pop();
//             TreeNode* t2 = q.front();
//             q.pop();
//             if (t1 == NULL && t2 == NULL) {
//                 continue;
//             }
//             if (t1 == NULL || t2 == NULL) {
//                 return false;
//             }
//             if (t1->val != t2->val) {
//                 return false;
//             }
//             q.push(t1->left);
//             q.push(t2->right);
//             q.push(t1->right);
//             q.push(t2->left);
//         }
//         return true;
//     }
// };

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return dfs(root, root);
    }
private:
    bool dfs(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL && t2 == NULL) {
            return true;
        }
        if (t1 == NULL || t2 == NULL) {
            return false;
        }
        if (t1->val != t2->val) {
            return false;
        }
        return dfs(t1->left, t2->right) && dfs(t1->right, t2->left);
    }
};
