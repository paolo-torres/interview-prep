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
        if (l1 == NULL && l2 == NULL) {
            return NULL;
        } else if (l1 != NULL && l2 == NULL) {
            return l1;
        } else if (l1 == NULL && l2 != NULL) {
            return l2;
        }
        ListNode* root = NULL;
        if (l1->val <= l2->val) {
            root = l1;
            l1 = l1->next;
        } else {
            root = l2;
            l2 = l2->next;
        }
        ListNode* head = root;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val <= l2->val) {
                root->next = l1;
                l1 = l1->next;
            } else {
                root->next = l2;
                l2 = l2->next;
            }
            root = root->next;
        }
        if (l1 != NULL) {
            root->next = l1;
        } else if (l2 != NULL) {
            root->next = l2;
        }
        return head;
    }
};
