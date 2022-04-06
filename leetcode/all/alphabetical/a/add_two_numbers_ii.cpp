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
        int i = 0;
        int j = 0;
        int carry = 0;
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        while (curr1 != NULL) {
            curr1 = curr1->next;
            i++;
        }
        while (curr2 != NULL) {
            curr2 = curr2->next;
            j++;
        }
        curr1 = l1;
        curr2 = l2;
        ListNode* result = NULL;
        while (i > 0 && j > 0) {
            int sum = 0;
            if (i >= j) {
                sum += curr1->val;
                curr1 = curr1->next;
                i--;
            }
            if (i < j) {
                sum += curr2->val;
                curr2 = curr2->next;
                j--;
            }
            ListNode* temp = new ListNode(sum);
            temp->next = result;
            result = temp;
        }
        curr1 = result;
        result = NULL;
        while (curr1 != NULL) {
            curr1->val += carry;
            carry = curr1->val / 10;
            curr1->val %= 10;
            ListNode* temp = new ListNode(curr1->val);
            temp->next = result;
            result = temp;
            curr2 = curr1;
            curr1 = curr1->next;
            delete curr2;
        }
        if (carry == 1) {
            ListNode* temp = new ListNode(carry);
            temp->next = result;
            result = temp;
        }
        return result;
    }
};
