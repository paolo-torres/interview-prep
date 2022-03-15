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
    int pathSum(TreeNode* root, int targetSum) {
        if (root == NULL) {
            return 0;
        }
        unordered_map<int, int> m;
        m[0] = 1;
        int result = 0;
        dfs(root, targetSum, 0, m, result);
        return result;
    }
private:
    void dfs(TreeNode* root, int targetSum, int currSum, unordered_map<int, int>& m, int& result) {
        if (root == NULL) {
            return;
        }
        
        currSum += root->val;
        int complement = currSum - targetSum;
        if (m.find(complement) != m.end()) {
            result += m[complement];
        }
        
        m[currSum]++;
        dfs(root->left, targetSum, currSum, m, result);
        dfs(root->right, targetSum, currSum, m, result);
        m[currSum]--;
    }
};
