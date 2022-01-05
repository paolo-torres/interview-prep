// Time: O(n log k)
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int> > pq;
        
        for (int i = 0; i < lists.size(); i++) {
            ListNode* node = lists[i];
            while (node != NULL) {
                pq.push(node->val);
                node = node->next;
            }
        }
        
        if (pq.empty()) {
            return NULL;
        }
        
        ListNode* root = new ListNode(pq.top());
        ListNode* head = root;
        pq.pop();
        
        while (!pq.empty()) {
            root->next = new ListNode(pq.top());
            root = root->next;
            pq.pop();
        }
        
        return head;
    }
};
