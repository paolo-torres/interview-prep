/*
    In a card game, each player given a set of random cards. Players
    will throw on the table their 1 winning card, the player with the
    highest card wins.
    A winning card is the card that only exists once in the set of
    cards, and is the highest one.
    Given an array of sets of cards, return card of winning player.
    Ex. Input: cards = [[5,7,3,9,4,9,8,3,1],[1,2,2,4,4,1],[1,2,3]]
        Output: 8
    
    Hash map of counts, store highest value with count of 1

    Time: O(n)
    Space: O(n)
*/

#include <stdio.h>

#include <iostream>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int winningCard(vector<vector<int>>& cards) {
        // {value -> count}
        unordered_map<int, int> m;
        for (int i = 0; i < cards.size(); i++) {
            for (int j = 0; j < cards[i].size(); j++) {
                m[cards[i][j]]++;
            }
        }

        int result = INT_MIN;
        for (auto it = m.begin(); it != m.end(); it++) {
            if (it->second == 1 && it->first > result) {
                result = it->first;
            }
        }
        return result == INT_MIN ? -1 : result;
    }
};

int main() {
    vector<vector<int>> cards1 = {
        {{5, 7, 3, 9, 4, 9, 8, 3, 1}, {1, 2, 2, 4, 4, 1}, {1, 2, 3}}
    };
    vector<vector<int>> cards2 = {
        {{5, 5}, {2, 2}}
    };
    Solution* obj = new Solution();
    cout << obj->winningCard(cards1) << " "
         << obj->winningCard(cards2) << endl;

    return 0;
}
