// Tree -> sorted array -> BST, can be optimized to O(1) space
// Tree -> vine (linked list) using left rotations, balance w/ right rotations

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
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> nums;
        inorder(root, nums);
        return dfs(nums, 0, nums.size() - 1);
    }
private:
    void inorder(TreeNode* root, vector<TreeNode*>& nums) {
        if (root == NULL) {
            return;
        }
        
        inorder(root->left, nums);
        nums.push_back(root);
        inorder(root->right, nums);
    }
    
    TreeNode* dfs(vector<TreeNode*>& nums, int start, int end) {
        if (start > end) {
            return NULL;
        }
        
        int mid = start + (end - start) / 2;
        TreeNode* root = nums[mid];
        
        root->left = dfs(nums, start, mid - 1);
        root->right = dfs(nums, mid + 1, end);
        
        return root;
    }
};
