// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/discuss/143798/1ms-beat-100-simple-Java-dfs-with(without)-hashmap-including-explanation

// Time: O(n)
// Space: O(n)

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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, int> m;
        findDistances(root, target, m);
        
        vector<int> result;
        dfs(root, k, 0, m, result);
        
        return result;
    }
private:
    void findDistances(TreeNode* root, TreeNode* target, unordered_map<TreeNode*, int>& m) {
        if (root == NULL) {
            return;
        }
        if (root == target) {
            m[root] = 0;
            return;
        }
        
        findDistances(root->left, target, m);
        if (m.find(root->left) != m.end()) {
            m[root] = m[root->left] + 1;
        }
        
        findDistances(root->right, target, m);
        if (m.find(root->right) != m.end()) {
            m[root] = m[root->right] + 1;
        }
    }
    
    void dfs(TreeNode* root, int k, int distance, unordered_map<TreeNode*, int>& m, vector<int>& result) {
        if (root == NULL) {
            return;
        }
        
        if (m.find(root) != m.end()) {
            distance = m[root];
        }
        if (distance == k) {
            result.push_back(root->val);
        }
        
        dfs(root->left, k, distance + 1, m, result);
        dfs(root->right, k, distance + 1, m, result);
    }
};
