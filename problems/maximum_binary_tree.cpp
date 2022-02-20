// Time: O(n^2)
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructTree(nums, 0, nums.size() - 1);
    }
private:
    TreeNode* constructTree(vector<int>& nums, int i, int j) {
        if (i > j) {
            return NULL;
        }
        
        int maxIndex = i;
        int maxValue = nums[i];
        
        for (int index = i; index <= j; index++) {
            if (nums[index] > maxValue) {
                maxIndex = index;
                maxValue = nums[index];
            }
        }
        
        TreeNode* root = new TreeNode(nums[maxIndex]);
        
        root->left = constructTree(nums, i, maxIndex - 1);
        root->right = constructTree(nums, maxIndex + 1, j);
        
        return root;
    }
};
