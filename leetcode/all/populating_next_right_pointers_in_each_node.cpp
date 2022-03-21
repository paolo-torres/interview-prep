// Time: O(n)
// Space: O(n)

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) {
            return NULL;
        }
        
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            int count = q.size();
            Node* rightNode = NULL;
            
            for (int i = count; i > 0; i--) {
                Node* node = q.front();
                q.pop();
                
                node->next = rightNode;
                rightNode = node;
                
                if (node->right != NULL) {
                    q.push(node->right);
                }
                if (node->left != NULL) {
                    q.push(node->left);
                }
            }
        }
        
        return root;
    }
};
