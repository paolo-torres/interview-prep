/*
    BSTIterator: next(): moves ptr to right, hasNext(): true if exists num to the right

    Controlled recursion, iterative DFS/in-order traversal, all the way left then right, repeat

    Time: O(1)
    Space: O(h)
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
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        while (root != NULL) {
            s.push(root);
            root = root->left;
        }
    }
    
    int next() {
        TreeNode* result = s.top();
        s.pop();
        
        TreeNode* curr = result->right;
        while (curr != NULL) {
            s.push(curr);
            curr = curr->left;
        }
        
        return result->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
private:
    stack<TreeNode*> s;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
