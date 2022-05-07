/*
    Given roots of 2 binary trees, check if they're the same or not (same structure & values)
    Ex. p = [1,2,3] q = [1,2,3] -> true, p = [1,2] q = [1,null,2] -> false

    Check: (1) matching nulls, (2) non-matching nulls, (3) non-matching values

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
//     bool isSameTree(TreeNode* p, TreeNode* q) {
//         queue<TreeNode*> queue;
//         queue.push(p);
//         queue.push(q);
//         while (!queue.empty()) {
//             TreeNode* curr2 = queue.front();
//             queue.pop();
//             TreeNode* curr1 = queue.front();
//             queue.pop();
//             if (curr1 == NULL && curr2 == NULL) {
//                 continue;
//             }
//             if (curr1 == NULL || curr2 == NULL) {
//                 return false;
//             }
//             if (curr1->val != curr2->val) {
//                 return false;
//             }
//             queue.push(curr1->left);
//             queue.push(curr2->left);
//             queue.push(curr1->right);
//             queue.push(curr2->right);
//         }
//         return true;
//     }
// };

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) {
            return true;
        }
        if (p == NULL || q == NULL) {
            return false;
        }
        if (p->val != q->val) {
            return false;
        }
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
