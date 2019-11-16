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
        } else if (l1 == NULL && l2 != NULL) {
            return l2;
        } else if (l1 == NULL && l2 == NULL) {
            return NULL;
        }
        ListNode* temp = NULL;
        if (l1->val <= l2->val) {
            temp = l1;
            l1 = l1->next;
        } else {
            temp = l2;
            l2 = l2->next;
        }
        ListNode* head = temp;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val <= l2->val) {
                temp->next = l1;
                l1 = l1->next;
            } else {
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }
        if (l1 != NULL) {
            temp->next = l1;
        } else if (l2 != NULL) {
            temp->next = l2;
        }
        return head;
    }
};