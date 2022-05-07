/*
    Given binary tree, find min depth (# of nodes along shortest path from root to leaf)

    DFS -> optimize w/ BFS, since will finish as soon as leaf node found

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
//     int minDepth(TreeNode* root) {
//         if (root == NULL) {
//             return 0;
//         }
//         int curr = 1;
//         int result = INT_MAX;
//         findDepth(root, curr, result);
//         return result;
//     }
// private:
//     void findDepth(TreeNode* root, int curr, int& result) {
//         if (root == NULL) {
//             return;
//         }
//         if (root->left == NULL && root->right == NULL) {
//             result = min(result, curr);
//         }
//         findDepth(root->left, curr + 1, result);
//         findDepth(root->right, curr + 1, result);
//     }
// };

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        
        int depth = 0;
        
        while (!q.empty()) {
            TreeNode* root = q.front().first;
            depth = q.front().second;
            q.pop();
            
            if (root->left == NULL && root->right == NULL) {
                break;
            }
            
            if (root->left != NULL) {
                q.push({root->left, depth + 1});
            }
            if (root->right != NULL) {
                q.push({root->right, depth + 1});
            }
        }
        
        return depth;
    }
};
