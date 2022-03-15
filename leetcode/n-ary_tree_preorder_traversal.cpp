/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
private:
    vector<int> result;
    void traverse(Node* root) {
        if (root == NULL) {
            return;
        }
        result.push_back(root->val);
        for (int i = 0; i < root->children.size(); i++) {
            traverse(root->children[i]);
        }
    }
public:
    vector<int> preorder(Node* root) {
        traverse(root);
        return result;
    }
};
