// Given root of binary tree: collect all leaf nodes, remove all leaf nodes, repeat until empty
// Ex. root = [1,2,3,4,5], output = [[4,5,3],[2],[1]]

// DFS, insert node values at correct locations

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
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> result;
        getHeight(root, result);
        return result;
    }
private:
    int getHeight(TreeNode* root, vector<vector<int>>& result) {
        if (root == NULL) {
            return -1;
        }
        
        // first calculate height of left & right children
        int leftHeight = getHeight(root->left, result);
        int rightHeight = getHeight(root->right, result);
        
        // based on heights, obtain height of curr (parent) node
        int currHeight = 1 + (max(leftHeight, rightHeight));
        
        // make space for node at "currHeight"
        if (result.size() == currHeight) {
            result.push_back({});
        }
        
        // insert value at correct position in array
        result[currHeight].push_back(root->val);
        return currHeight;
    }
};
