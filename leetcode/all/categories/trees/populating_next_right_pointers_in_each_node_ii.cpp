// Level order traversal, at each level fix all next pointers beneath

// Time: O(n)
// Space: O(1)

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
        // curr node of curr level
        Node* curr = root;
        // head of next level
        Node* head = NULL;
        // leading node of next level
        Node* prev = NULL;
        
        while (curr != NULL) {
            // iterate on curr level
            while (curr != NULL) {
                // left child
                if (curr->left != NULL) {
                    if (prev != NULL) {
                        prev->next = curr->left;
                    } else {
                        head = curr->left;
                    }
                    prev = curr->left;
                }
                
                // right child
                if (curr->right != NULL) {
                    if (prev != NULL) {
                        prev->next = curr->right;
                    } else {
                        head = curr->right;
                    }
                    prev = curr->right;
                }
                
                // move to next node
                curr = curr->next;
            }
            
            // move to next level
            curr = head;
            head = NULL;
            prev = NULL;
        }
        
        return root;
    }
};
