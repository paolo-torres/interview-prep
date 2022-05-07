/*
    Given head of sorted linked list, delete all duplicates
    Ex. head = [1,1,2] -> [1,2]

    Compare adjacent nodes, remove by changing prev->next ptr

    Time: O(n)
    Space: O(1)
*/

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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        
        while (curr != NULL) {
            if (prev->val == curr->val) {
                prev->next = curr->next;
                curr = curr->next;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        
        return head;
    }
};
