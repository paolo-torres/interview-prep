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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pIndex = 0;
        unordered_map<int, int> iMap;
        
        for (int i = 0; i < inorder.size(); i++) {
            iMap[inorder[i]] = i;
        }
        
        return build(preorder, pIndex, iMap, 0, preorder.size() - 1);
    }
private:
    TreeNode* build(vector<int>& preorder, int& pIndex, unordered_map<int, int>& iMap, int left, int right) {
        if (left > right) {
            return NULL;
        }
        
        int pValue = preorder[pIndex];
        pIndex++;
        int iIndex = iMap[pValue];
        
        TreeNode* root = new TreeNode(pValue);
        root->left = build(preorder, pIndex, iMap, left, iIndex - 1);
        root->right = build(preorder, pIndex, iMap, iIndex + 1, right);
        
        return root;
    }
};
