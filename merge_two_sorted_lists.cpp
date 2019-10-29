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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 != NULL && l2 == NULL) {
            return l1;
        }
        if (l1 == NULL && l2 != NULL) {
            return l2;
        }
        if (l1 == NULL && l2 == NULL) {
            return NULL;
        }
        ListNode* l;
        if (l1->val <= l2->val) {
            l = l1;
            l1 = l1->next;
        } else {
            l = l2;
            l2 = l2->next;
        }
        ListNode* head = l;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val <= l2->val) {
                l->next = l1;
                l1 = l1->next;
            } else {
                l->next = l2;
                l2 = l2->next;
            }
            l = l->next;
        }
        if (l1 != NULL) {
            l->next = l1;
        } else if (l2 != NULL) {
            l->next = l2;
        }
        return head;
    }
};
