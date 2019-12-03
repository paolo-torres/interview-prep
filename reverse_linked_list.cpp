/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* trail = NULL;
        ListNode* curr = head;
        ListNode* next = head->next;
        while (curr != NULL) {
            next = curr->next;
            curr->next = trail;
            trail = curr;
            curr = next;
        }
        head = trail;
        return head;
    }
};
