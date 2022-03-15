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
private:
    void traverse(TreeNode* root, map<int, map<int, set<int>>>& nodes, int x, int y) {
        if (root == NULL) {
            return;
        }
        traverse(root->left, nodes, x - 1, y + 1);
        nodes[x][y].insert(root->val);
        traverse(root->right, nodes, x + 1, y + 1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL) {
            return result;
        }
        map<int, map<int, set<int>>> nodes;
        traverse(root, nodes, 0, 0);
        for (auto x = nodes.begin(); x != nodes.end(); x++) {
            vector<int> col;
            for (auto y = x->second.begin(); y != x->second.end(); y++) {
                col.insert(col.end(), y->second.begin(), y->second.end());
            }
            result.push_back(col);
        }
        return result;
    }
};
