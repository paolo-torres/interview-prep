// Similar to validate BST, trailing node + fix pointers

// Time: O(n)
// Space: O(n)

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (root == NULL) {
            return NULL;
        }
        
        Node* head = NULL;
        Node* tail = NULL;
        
        dfs(root, head, tail);
        head->left = tail;
        tail->right = head;
        
        return head;
    }
private:
    void dfs(Node* node, Node*& head, Node*& tail) {
        if (node == NULL) {
            return;
        }
        
        dfs(node->left, head, tail);
        
        if (tail != NULL) {
            tail->right = node;
            node->left = tail;
        } else {
            head = node;
        }
        tail = node;
        
        dfs(node->right, head, tail);
    }
};
