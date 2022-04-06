// Time: O(n)
// Space: O(m)

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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        vector<double> result;
        
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            double sum = 0.0;
            
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                sum += node->val;
                
                if (node->left != NULL) {
                    q.push(node->left);
                }
                if (node->right != NULL) {
                    q.push(node->right);
                }
            }
            
            result.push_back(sum / n);
        }
        
        return result;
    }
};
