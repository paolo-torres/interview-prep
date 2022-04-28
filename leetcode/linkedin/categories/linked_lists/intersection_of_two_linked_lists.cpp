/*
    Given heads of 2 linked lists, return node of intersection
    Ex. listA = [4,1,8,4,5], listB = [5,6,1,8,4,5] -> 8

    Brute force -> hash table -> 2 pointers, shared tail, calculate diff

    Time: O(m + n)
    Space: O(1)
*/

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        while (p1 != p2) {
            p1 = p1 == NULL ? headB : p1->next;
            p2 = p2 == NULL ? headA : p2->next;
        }
        // if no intersection, would return NULL, which is correct
        return p1;
    }
};
