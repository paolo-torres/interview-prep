/*
    Given linked list of cards, split, shuffle, and merge the cards.
    Ex. ['A','4','6','7','9','K','Q','J','2']
        Split: ['A'->'4'->'6'->'7', '9'->'K'->'Q', 'J'->'2']
        Merge Randomly: ['9'->'6'->'7'->'K'->'Q'->'J'->'2'->'4'->'A']

    Time: O()
    Space: O()
*/

#include <stdio.h>

#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct ListNode {
    char val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(char x) : val(x), next(nullptr) {}
    ListNode(char x, ListNode *next) : val(x), next(next) {}
};

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

    ListNode* mergeListFromParts(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }
        ListNode* result = l1;
        while (l1 != NULL && l2 != NULL) {
            ListNode* temp1 = l1->next;
            ListNode* temp2 = l2->next;
            if (l1->next != NULL) {
                l2->next = l1->next;
            }
            l1->next = l2;
            l1 = temp1;
            l2 = temp2;
        }
        return result;
    }
};

int main() {
    ListNode* list = new ListNode('A', new ListNode('4',
                     new ListNode('6', new ListNode('7',
                     new ListNode('9', new ListNode('K',
                     new ListNode('Q', new ListNode('J',
                     new ListNode('2')))))))));
    Solution* obj = new Solution();

    vector<ListNode*> split = obj->splitListToParts(list, 2);
    for (int i = 0; i < split.size(); i++) {
        ListNode* head = split[i];
        while (head != NULL) {
            cout << head->val << " -> ";
            head = head->next;
        }
        cout << endl;
    }
    cout << endl;

    ListNode* result = obj->mergeListFromParts(split[0], split[1]);
    ListNode* head = result;
    while (head != NULL) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << endl;

    return 0;
}
