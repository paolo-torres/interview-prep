/*
    Given head of linked list & k, split into k parts as equally as possible
    Ex. head = [1,2,3,4,5,6,7,8,9,10], k = 3 -> [[1,2,3,4],[5,6,7],[8,9,10]]

    If n nodes, then n / k nodes in each part, plus 1st n % k parts have extra

    Time: O(n + k)
    Space: O(k)
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* curr = head;
        int n = 0;
        while (curr != NULL) {
            n++;
            curr = curr->next;
        }
        
        int width = n / k;
        int remainder = n % k;
        
        curr = head;
        vector<ListNode*> result;
        for (int i = 0; i < k; i++) {
            ListNode* node = curr;
            for (int j = 0; j < width + (i < remainder ? 1 : 0) - 1; j++) {
                if (curr != NULL) {
                    curr = curr->next;
                }
            }
            if (curr != NULL) {
                ListNode* prev = curr;
                curr = curr->next;
                prev->next = NULL;
            }
            result.push_back(node);
        }
        return result;
    }
};
