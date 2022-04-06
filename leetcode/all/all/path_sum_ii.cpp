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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> curr;
        vector<vector<int>> result;
        if (root == NULL) {
            return result;
        }
        dfs(root, targetSum, 0, curr, result);
        return result;
    }
private:
    void dfs(TreeNode* root, int targetSum, int sum, vector<int>& curr, vector<vector<int>>& result) {
        if (root == NULL) {
            return;
        }
        
        curr.push_back(root->val);
        dfs(root->left, targetSum, sum + root->val, curr, result);
        
        if (root->left == NULL && root->right == NULL) {
            if (sum + root->val == targetSum) {
                result.push_back(curr);
            }
        }
        
        dfs(root->right, targetSum, sum + root->val, curr, result);
        curr.pop_back();
    }
};
