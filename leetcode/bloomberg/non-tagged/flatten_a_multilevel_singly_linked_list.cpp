/*
    Given a multilevel singly linked list, flatten the list

    For each child, merge chain back to main

    Time: O(n)
    Space: O(1)
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
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

        // find tail node of first level
        Node* tail = head;
        while (tail->next != NULL) {
            tail = tail->next;
        }

        // traverse thru all nodes of first level until tail
        Node* curr = head;
        Node* temp = NULL;
        while (curr != tail) {
            if (curr->child != NULL) {
                // append child to end of current list
                tail->next = curr->child;

                // update tail to new last
                temp = curr->child;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                tail = temp;
            }
            curr = curr->next;
        }

        return head;
    }
};
