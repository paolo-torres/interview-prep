// Given root of BST, a target value, & an int k, return k values in BST closest to target
// Ex. root = [4,2,5,1,3], target = 3.714286, k = 2 -> output = [4,3]

// Maintain all predecessors & successors in 2 stacks (stack to track paths from root to curr)
// This works because BST's are in a certain order, so going outwards from closest values is best

// Time: O(log (n) + k) -> log (n) assuming BST is balanced, k to build output
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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        stack<TreeNode*> pre;
        stack<TreeNode*> suc;
        buildPre(root, target, pre);
        buildSuc(root, target, suc);
        
        // if there exists a node with val = target
        if (!pre.empty() && !suc.empty() && pre.top() == suc.top()) {
            getPre(pre);
        }
        
        vector<int> result;
        for (int i = 0; i < k; i++) {
            if (pre.empty()) {
                result.push_back(getSuc(suc));
            } else if (suc.empty()) {
                result.push_back(getPre(pre));
            } else {
                double preDiff = abs((double) pre.top()->val - target);
                double sucDiff = abs((double) suc.top()->val - target);
                if (preDiff < sucDiff) {
                    result.push_back(getPre(pre));
                } else {
                    result.push_back(getSuc(suc));
                }
            }
        }
        return result;
    }
private:
    // build predecessors (contains only elements smaller than target)
    void buildPre(TreeNode* root, double target, stack<TreeNode*>& pre) {
        TreeNode* node = root;
        while (node != NULL) {
            if (node->val == target) {
                pre.push(node);
                break;
            } else if (node->val < target) {
                pre.push(node);
                node = node->right;
            } else {
                node = node->left;
            }
        }
    }
    
    // build successors (contains only elements larger than target)
    void buildSuc(TreeNode* root, double target, stack<TreeNode*>& suc) {
        TreeNode* node = root;
        while (node != NULL) {
            if (node->val == target) {
                suc.push(node);
                break;
            } else if (node->val > target) {
                suc.push(node);
                node = node->left;
            } else {
                node = node->right;
            }
        }
    }
    
    // get biggest element that's smaller
    int getPre(stack<TreeNode*>& pre) {
        TreeNode* node = pre.top();
        pre.pop();
        int result = node->val;
        node = node->left;
        while (node != NULL) {
            pre.push(node);
            node = node->right;
        }
        return result;
    }
    
    // get smallest element that's bigger
    int getSuc(stack<TreeNode*>& suc) {
        TreeNode* node = suc.top();
        suc.pop();
        int result = node->val;
        node = node->right;
        while (node != NULL) {
            suc.push(node);
            node = node->left;
        }
        return result;
    }
};
