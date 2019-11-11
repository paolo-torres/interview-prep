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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL || head->next == NULL && n == 1 || n == 0) {
            return NULL;
        }
        ListNode* curr = head;
        for (int i = 0; i < n; i++) {
            curr = curr->next;
        }
        if (curr == NULL) {
            return head->next;
        }
        ListNode* trail = head;
        while (curr->next != NULL) {
            trail = trail->next;
            curr = curr->next;
        }
        trail->next = trail->next->next;
        return head;
    }
};
