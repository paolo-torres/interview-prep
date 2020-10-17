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
        Node* root = head;
        while (root != NULL) {
            if (root->child != NULL) {
                Node* temp = root->next;
                root->next = root->child;
                root->next->prev = root;
                root->child = NULL;
                Node* p = root->next;
                while (p->next != NULL) {
                    p = p->next;
                }
                p->next = temp;
                if (temp != NULL) {
                    temp->prev = p;
                }
            }
            root = root->next;
        }
        return head;
    }
};
