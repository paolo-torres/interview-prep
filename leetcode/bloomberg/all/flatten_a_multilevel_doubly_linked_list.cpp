// For each child, merge chain back to main

// Time: O(n)
// Space: O(1)

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (head == NULL) {
            return NULL;
        }
        
        Node* root = head;
        
        while (root != NULL) {
            // if no child, just move on
            if (root->child == NULL) {
                root = root->next;
                continue;
            }
            
            // if child, find end & link
            Node* temp = root->next;
            root->next = root->child;
            root->next->prev = root;
            root->child = NULL;
            // find tail of the child
            Node* p = root->next;
            while (p->next != NULL) {
                p = p->next;
            }
            // connect tail with main level
            p->next = temp;
            if (temp != NULL) {
                temp->prev = p;
            }
            
            root = root->next;
        }
        
        return head;
    }
};
