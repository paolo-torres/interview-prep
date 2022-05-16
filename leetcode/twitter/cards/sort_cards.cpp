/*
    Sort cards.

    Time: O(1)
    Space: O(1)
*/

#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <queue>
#include <map>
#include <stack>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct Card {
    int suit; // 0 - spade, 1 - heart, 2 - club, 3 - diamond
    int val;
};

class Solution {
public:
    void sortCards(vector<Card*>& unsorted, vector<Card*>& sorted) {
        sorted = unsorted;
        for (int i = 0; i < unsorted.size(); i++) {
            Card* card = unsorted[i];
            int index = card->suit * 13 + card->val - 1;
            sorted[index] = unsorted[i];
        }
    }
};

int main() {
    Solution* obj = new Solution();
    
    return 0;
}
