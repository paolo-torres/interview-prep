// Time: O(max(m, n))
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* prev = l1;
        ListNode* head = l1;
        
        while (l1 != NULL && l2 != NULL) {
            l1->val += l2->val + carry;
            if (l1->val >= 10) {
                l1->val %= 10;
                carry = 1;
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
            l1->val += carry;
            if (l1->val >= 10) {
                l1->val %= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            if (l1->next == NULL) {
                prev = l1;
            }
            l1 = l1->next;
        }
        
        while (l2 != NULL) {
            prev->next = new ListNode(l2->val + carry);
            prev = prev->next;
            if (prev->val >= 10) {
                prev->val %= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            l2 = l2->next;
        }
        
        if (carry == 1) {
            prev->next = new ListNode(carry);
        }
        
        return head;
    }
};
