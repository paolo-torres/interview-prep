/*
    Given head of linked list, rotate list to the right by k
    Ex. head = [1,2,3,4,5], k = 2 -> [4,5,1,2,3]

    Close linked list into ring, break ring after new tail

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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        int size = 1;
        ListNode* curr = head;
        while (curr->next != NULL) {
            size++;
            curr = curr->next;
        }
        curr->next = head;
        
        int newHead = size - k % size;
        for (int i = 0; i < newHead; i++) {
            curr = curr->next;
        }
        
        head = curr->next;
        curr->next = NULL;
        return head;
    }
};
