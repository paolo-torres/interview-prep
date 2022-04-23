/*
    Given binary tree, return step-by-step directions of shortest path from node s to node t
    Ex. root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6 -> "UURL", up, up, right, left

    First find LCA, then get paths from LCA to start & dest (add 'L' when left, 'R' when right)
    Finally, convert LCA to start path to all 'U' since this path moves upwards

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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        // get LCA of start & destination nodes
        TreeNode* lca = lowestCommonAncestor(root, startValue, destValue);
        
        string lcaToStart = "";
        string lcaToDest = "";
        
        // find paths from LCA to start & destination
        dfs(lca, startValue, lcaToStart);
        dfs(lca, destValue, lcaToDest);
        
        // since start to LCA moves upward, convert all to 'U'
        for (int i = 0; i < lcaToStart.size(); i++) {
            lcaToStart[i] = 'U';
        }
        
        return lcaToStart + lcaToDest;
    }
private:
    TreeNode* lowestCommonAncestor(TreeNode* root, int startValue, int destValue) {
        if (root == NULL || root->val == startValue || root->val == destValue) {
            return root;
        }
        
        TreeNode* left = lowestCommonAncestor(root->left, startValue, destValue);
        TreeNode* right = lowestCommonAncestor(root->right, startValue, destValue);
        
        if (left == NULL) {
            return right;
        }
        if (right == NULL) {
            return left;
        }
        
        return root;
    }
    
    bool dfs(TreeNode* root, int value, string& path) {
        if (root == NULL) {
            return false;
        }
        // if node found we have our path
        if (root->val == value) {
            return true;
        }
        
        // try to find node in left direction
        path += 'L';
        if (dfs(root->left, value, path)) {
            return true;
        }
        path.pop_back();
        
        // try to find node in right direction
        path += 'R';
        if (dfs(root->right, value, path)) {
            return true;
        }
        path.pop_back();
        
        return false;
    }
};
