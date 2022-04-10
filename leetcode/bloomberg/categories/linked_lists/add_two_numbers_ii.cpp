// Sum nodes & add to front w/o carry, then consider carry & reverse

// Time: O(m + n)
// Space: O(max(m, n))

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
        // get length of both lists
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        int i = 0;
        int j = 0;
        while (curr1 != NULL) {
            curr1 = curr1->next;
            i++;
        }
        while (curr2 != NULL) {
            curr2 = curr2->next;
            j++;
        }
        
        // sum nodes w/o taking into account the carry
        // ex. 3->3->3 + 7->7 = 3->10->10 --> 10->10->3
        curr1 = l1;
        curr2 = l2;
        ListNode* head = NULL;
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
            head = addToFront(sum, head);
        }
        
        // now take into account the carry so all nodes < 10
        // ex. 10->10->3 --> 0->1->4 --> 4->1->0
        int carry = 0;
        curr1 = head;
        head = NULL;
        while (curr1 != NULL) {
            int sum = (curr1->val + carry) % 10;
            carry = (curr1->val + carry) / 10;
            head = addToFront(sum, head);
            curr1 = curr1->next;
        }
        
        if (carry == 1) {
            head = addToFront(carry, head);
        }
        
        return head;
    }
private:
    ListNode* addToFront(int value, ListNode* head) {
        ListNode* curr = new ListNode(value);
        curr->next = head;
        return curr;
    }
};
