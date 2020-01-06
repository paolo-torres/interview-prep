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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < lists.size(); i++) {
            while (lists[i] != NULL) {
                pq.push(lists[i]->val);
                lists[i] = lists[i]->next;
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
