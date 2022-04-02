// Stack, top of stack is parent, build subtrees, ')' means done w/ subtree so pop from stack

// Time: O(n)
// Space: O(h)

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
    TreeNode* str2tree(string s) {
        int n = s.size();
        if (n == 0) {
            return NULL;
        }
        stack<TreeNode*> stk;
        
        for (int i = 0, j = 0; j < n; i = j + 1, j++) {
            if (s[j] == ')') {
                stk.pop();
            } else if (s[j] >= '0' && s[j] <= '9' || s[j] == '-') {
                while (j + 1 < n && s[j + 1] >= '0' && s[j + 1] <= '9') {
                    j++;
                }
                
                int value = stoi(s.substr(i, j - i + 1));
                TreeNode* node = new TreeNode(value);
                
                if (!stk.empty()) {
                    TreeNode* parent = stk.top();
                    if (parent->left == NULL) {
                        parent->left = node;
                    } else {
                        parent->right = node;
                    }
                }
                
                stk.push(node);
            }
        }
        
        return stk.top();
    }
};
