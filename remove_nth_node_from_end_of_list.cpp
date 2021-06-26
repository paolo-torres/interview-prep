// Time: O(n)
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next == NULL) {
            return NULL;
        }
        
        ListNode* root = head;
        for (int i = 0; i < n; i++) {
            root = root->next;
        }
        
        if (root == NULL) {
            return head->next;
        }
        
        ListNode* trail = head;
        while (root->next != NULL) {
            trail = trail->next;
            root = root->next;
        }
        trail->next = trail->next->next;
        
        return head;
    }
};
