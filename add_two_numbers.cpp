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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* prev = l1;
        ListNode* head = l1;
        while (l1 != NULL && l2 != NULL) {
            l1->val = l1->val + l2->val + carry;
            if (l1->val >= 10) {
                carry = 1;
                l1->val %= 10;
            } else {
                carry = 0;
            }
            if (l1->next == NULL) {
                prev = l1;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != NULL) {
            l1->val = l1->val + carry;
            if (l1->val >= 10) {
                carry = 1;
                l1->val %= 10;
            } else {
                carry = 0;
            }
            prev = l1;
            l1 = l1->next;
        }
        while (l2 != NULL) {
            prev->next = l2;
            prev->next->val = l2->val + carry;
            if (prev->next->val >= 10) {
                carry = 1;
                prev->next->val %= 10;
            } else {
                carry = 0;
            }
            prev = l2;
            l2 = l2->next;
        }
        if (carry == 1) {
            ListNode* temp = new ListNode(carry);
            prev->next = temp;
        }
        return head;
    }
};
