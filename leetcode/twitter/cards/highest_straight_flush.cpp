/*
    Given deck of card, find highest (if any) 5 straight flush (i.e.,
    5 cards of the same suit with consecutive numbers).
    Ex. Given a card of suit "1" with rank "0" -> S1R0.
        Input: [S0R7, S2R0, S0R1, S2R1, S2R2, S2R3, S2R5, S2R4]
        Output: [S2R1, S2R2, S2R3, S2R4, S2R5]

    Count suit/rank combos in matrix, iterate backwards, store max

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

class Card {
public:
    Card(int s, int r) {
        suit = s;
        rank = r;
    }
    int suit; // 0-3
    int rank; // 0-12
};

class Solution {
public:
    void findHighestStraightFlush(vector<Card*>& cards) {
        vector<vector<int>> dp(4, vector<int>(13));
        for (int i = 0; i < cards.size(); i++) {
            dp[cards[i]->suit][cards[i]->rank] = 1;
        }

        vector<int> result(4);
        for (int i = dp.size() - 1; i >= 0; i--) {
            int row = i;
            for (int j = dp[i].size() - 1; j >= 0; j--) {
                int col = j;
                int count = 5;

                while (col >= 0 && col >= j - 4 && dp[row][col] == 1) {
                    col--;
                    count--;
                }

                if (count == 0) {
                    result[row] = j;
                    break;
                }
            }
        }

        int maxRow = -1;
        int maxIndex = -1;
        for (int i = 0; i < result.size(); i++) {
            if (result[i] > maxIndex) {
                maxRow = i;
                maxIndex = result[i];
            }
        }

        int i = maxIndex;
        while (i >= maxIndex - 4) {
            cout << "S: " << maxRow << " R: " << i << endl;
            i--;
        }
    }
};

int main() {
    vector<Card*> cards;
    cards.push_back(new Card(0, 7));
    cards.push_back(new Card(2, 0));
    cards.push_back(new Card(0, 1));
    cards.push_back(new Card(2, 1));
    cards.push_back(new Card(2, 2));
    cards.push_back(new Card(2, 3));
    cards.push_back(new Card(2, 5));
    cards.push_back(new Card(2, 4));
    Solution* obj = new Solution();
    obj->findHighestStraightFlush(cards);

    return 0;
}
