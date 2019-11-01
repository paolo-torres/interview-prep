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
        int temp = 0;
        ListNode* head = l1;
        ListNode* trail = l1;
        while (l1 != NULL && l2 != NULL) {
            l1->val = l1->val + l2->val + carry;
            carry = 0;
            if (l1->val >= 10) {
                temp = l1->val;
                l1->val %= 10;
                carry = temp / 10;
            }
            if (l1->next == NULL) {
                trail = l1;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l1 != NULL) {
            while (l1 != NULL) {
                l1->val = l1->val + carry;
                if (l1->val >= 10) {
                    temp = l1->val;
                    l1->val %= 10;
                    carry = temp / 10;                
                } else {
                    carry = 0;
                }
                trail = l1;
                l1 = l1->next;
            }
        }
        if (l2 != NULL) {
            while (l2 != NULL) {
                trail->next = l2;
                trail->next->val = l2->val + carry;
                if (trail->next->val >= 10) {
                    temp = trail->next->val;
                    trail->next->val %= 10;
                    carry = temp / 10;
                } else {
                    carry = 0;
                }
                trail = l2;
                l2 = l2->next;
            }
        }
        if (carry != 0) {
            ListNode* newNode = new ListNode(carry);
            newNode->next = NULL;
            while (trail->next != NULL) {
                trail = trail->next;
            }
            trail->next = newNode;
        }
        return head;
    }
};
