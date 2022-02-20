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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, unsigned int>> q;
        q.push({root, 1});
        
        unsigned int result = 0;
        
        while (!q.empty()) {
            int count = q.size();
            
            unsigned int start = q.front().second;
            unsigned int end = 0;
            
            for (int i = 0; i < count; i++) {
                TreeNode* node = q.front().first;
                end = q.front().second;
                q.pop();
                
                if (node->left != NULL) {
                    q.push({node->left, end * 2});
                }
                if (node->right != NULL) {
                    q.push({node->right, end * 2 + 1});
                }
            }
            
            result = max(result, end - start + 1);
        }
        
        return result;
    }
};
