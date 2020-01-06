/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return head;
        }
        Node* curr = head;
        Node* temp;
        while (curr != NULL) {
            temp = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = temp;
            curr = temp;
        }
        curr = head;
        while (curr != NULL) {
            if (curr->next != NULL && curr->random != NULL) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next ? curr->next->next : curr->next;
        }
        Node* orig = head;
        Node* copy = head->next;
        temp = copy;
        while (orig != NULL && copy != NULL) {
            orig->next = orig->next ? orig->next->next : orig->next;
            copy->next = copy->next ? copy->next->next : copy->next;
            orig = orig->next;
            copy = copy->next;
        }
        return temp;
    }
};
