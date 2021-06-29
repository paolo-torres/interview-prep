// Time: O(n)
// Space: O(1)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if (head->next == NULL) {
            return;
        }
        
        ListNode* p1 = head;
        ListNode* p2 = head;
        
        while (p2->next != NULL && p2->next->next != NULL) {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        
        ListNode* prev = p1;
        ListNode* curr = p1->next;
        ListNode* next = NULL;
        
        while (curr->next != NULL) {
            next = curr->next;
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
        }
        
        p1 = head;
        p2 = prev->next;
        
        while (p1 != prev) {
            prev->next = p2->next;
            p2->next = p1->next;
            p1->next = p2;
            p1 = p2->next;
            p2 = prev->next;
        }
    }
};
