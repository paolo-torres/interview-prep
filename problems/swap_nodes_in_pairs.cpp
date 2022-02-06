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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode* dummy = new ListNode();
        dummy->next = head;
        
        ListNode* curr = dummy;
        
        while (curr->next != NULL && curr->next->next != NULL) {
            ListNode* p1 = curr->next;
            ListNode* p2 = curr->next->next;
            
            curr->next = p2;
            p1->next = p2->next;
            
            p2->next = p1;
            curr = p1;
        }
        
        return dummy->next;
    }
};
