/*
    Given binary tree with values [0, 25] for 'a'-'z', return lexically smallest string from leaf to root

    DFS + backtracking, insert curr value in front & pop once done with curr

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
class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        string result = "";
        dfs(root, "", result);
        return result;
    }
private:
    void dfs(TreeNode* root, string curr, string& result) {
        if (root == NULL) {
            return;
        }
        
        curr.insert(curr.begin(), 'a' + root->val);
        
        if (root->left == NULL && root->right == NULL) {
            if (result == "") {
                result = curr;
            } else {
                result = min(result, curr);
            }
        }
        
        dfs(root->left, curr, result);
        dfs(root->right, curr, result);
        
        curr = "";
    }
};
