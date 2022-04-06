// DFS preorder traversal, optimize space w/ Morris traversal O(1)
// Morris: set temp link b/w node & predecessor if possible

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

// // Time: O(n)
// // Space: O(n)

// class Solution {
// public:
//     int sumNumbers(TreeNode* root) {
//         int result = 0;
//         dfs(root, "", result);
//         return result;
//     }
// private:
//     void dfs(TreeNode* root, string str, int& result) {
//         if (root == NULL) {
//             return;
//         }
        
//         str += (root->val + '0');
//         if (root->left == NULL && root->right == NULL) {
//             result += stoi(str);
//         }
        
//         dfs(root->left, str, result);
//         dfs(root->right, str, result);
//     }
// };

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        TreeNode* predecessor = NULL;
        int steps = 0;
        
        int curr = 0;
        int result = 0;
        
        while (root != NULL) {
            // if there is left child, compute predecessor
            if (root->left != NULL) {
                // predecessor is 1 step left then all the way right
                predecessor = root->left;
                steps = 1;
                while (predecessor->right != NULL && predecessor->right != root) {
                    predecessor = predecessor->right;
                    steps++;
                }
                
                // set link & explore left subtree
                if (predecessor->right == NULL) {
                    curr = curr * 10 + root->val;
                    predecessor->right = root;
                    root = root->left;
                // break link, change subtree & go to right
                } else {
                    // if on leaf, update sum
                    if (predecessor->left == NULL) {
                        result += curr;
                    }
                    
                    // already explored, backtrack sum
                    for (int i = 0; i < steps; i++) {
                        curr /= 10;
                    }
                    
                    predecessor->right = NULL;
                    root = root->right;
                }
            // if there is no left child, then just go right
            } else {
                curr = curr * 10 + root->val;
                // if on leaf, update sum
                if (root->right == NULL) {
                    result += curr;
                }
                root = root->right;
            }
        }
        
        return result;
    }
};
