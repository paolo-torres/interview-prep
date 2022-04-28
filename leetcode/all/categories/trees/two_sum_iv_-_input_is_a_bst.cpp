/*
    Given root of a BST & a target k, return true if 2 elements in the BST sum to target
    root = [5,3,6,2,4,null,7], k = 9 -> true, 5 + 4

    Use BST property, inorder traversal creates sorted array, 2 pointers outside in

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
    bool findTarget(TreeNode* root, int k) {
        vector<int> nums;
        inorder(root, nums);
        
        int i = 0;
        int j = nums.size() - 1;
        
        while (i < j) {
            int sum = nums[i] + nums[j];
            if (sum < k) {
                i++;
            } else if (sum > k) {
                j--;
            } else {
                return true;
            }
        }
        
        return false;
    }
private:
    void inorder(TreeNode* root, vector<int>& nums) {
        if (root == NULL) {
            return;
        }
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }
};
