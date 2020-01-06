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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        int result = 0;
        while (!q.empty()) {
            int size = q.size();
            if (size == 1) {
                q.push({q.front().first, 1});
                q.pop();
            }
            result = max(result, q.back().second - q.front().second + 1);
            while (size > 0) {
                auto node = q.front().first;
                auto id = q.front().second;
                q.pop();
                if (node->left != NULL) {
                    q.push({node->left, id * 2});
                }
                if (node->right != NULL) {
                    q.push({node->right, id * 2 + 1});
                }
                size--;
            }
        }
        return result;
    }
};
