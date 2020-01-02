/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL) {
            return result;
        }
        deque<TreeNode*> curr;
        deque<TreeNode*> next;
        curr.push_back(root);
        vector<int> temp;
        int level = 0;
        while (!curr.empty()) {
            auto it = curr.front();
            curr.pop_front();
            temp.push_back(it->val);
            if (it->left != NULL) {
                next.push_back(it->left);
            }
            if (it->right != NULL) {
                next.push_back(it->right);
            }
            if (curr.empty()) {
                if (level % 2 != 0) {
                    reverse(temp.begin(), temp.end());
                }
                level++;
                result.push_back(temp);
                temp.clear();
                swap(curr, next);
            }
        }
        return result;
    }
};
