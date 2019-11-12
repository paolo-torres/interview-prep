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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        ListNode* fix = head;
        bool afterInit = false;
        while (fast != NULL) {
            ListNode* temp = fast->next;
            fast->next = slow;
            slow->next = temp;
            if (afterInit) {
                fix->next = fast;
                fix = fix->next->next;
            } else {
                fix->next = temp;
                head = fast;
            }
            slow = temp;
            if (temp == NULL) {
                fast = temp;
            } else {
                fast = temp->next;
            }
            afterInit = true;
        }
        return head;
    }
};
