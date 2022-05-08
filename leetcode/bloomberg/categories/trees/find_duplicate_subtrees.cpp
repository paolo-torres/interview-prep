/*
    Given root of binary tree, return all duplicate subtrees (same structure & node values)

    Postorder traversal (because need structure), serialize & hash, detect dupes

    Time: O(n^2)
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
class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        // {hash of subtree as a string -> count}
        unordered_map<string, int> m;
        vector<TreeNode*> result;
        dfs(root, m, result);
        return result;
    }
private:
    string dfs(TreeNode* root, unordered_map<string, int>& m, vector<TreeNode*>& result) {
        if (root == NULL) {
            return "";
        }
        string s = to_string(root->val) + ","
                   + dfs(root->left, m, result) + "," + dfs(root->right, m, result);
        if (m[s] == 1) {
            result.push_back(root);
        }
        m[s]++;
        return s;
    }
};
