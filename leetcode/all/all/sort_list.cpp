// Time: O(n log n)
// Space: O(n)

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
    ListNode* sortList(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        
        vector<int> nums;
        ListNode* node = head;
        
        while (node != NULL) {
            nums.push_back(node->val);
            node = node->next;
        }
        
        sort(nums.begin(), nums.end());
        int i = 0;
        node = head;
        
        while (node != NULL) {
            node->val = nums[i];
            i++;
            node = node->next;
        }
        
        return head;
    }
};
