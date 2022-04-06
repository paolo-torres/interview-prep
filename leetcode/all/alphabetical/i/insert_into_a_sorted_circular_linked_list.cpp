// Insert in 3 cases, else insert anywhere
// 1. prev <= val <= curr
// 2. max (prev) < val
// 3. val < min (curr)

// Time: O(n)
// Space: O(1)

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (head == NULL) {
            head = new Node(insertVal);
            head->next = head;
            return head;
        }
        
        Node* prev = head;
        Node* curr = head->next;
        
        bool inserted = false;
        
        while (true) {
            if (prev->val <= insertVal && insertVal <= curr->val
                || prev->val > curr->val && prev->val < insertVal
                || prev->val > curr->val && insertVal < curr->val) {
                prev->next = new Node(insertVal, curr);
                inserted = true;
                break;
            }
            
            prev = prev->next;
            curr = curr->next;
            
            if (prev == head) {
                break;
            }
        }
        
        if (!inserted) {
            prev->next = new Node(insertVal, curr);
        }
        
        return head;
    }
};
