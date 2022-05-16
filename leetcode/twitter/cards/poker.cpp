/*
    Given 4 suits: Spades, Hearts, Clubs, and Diamonds & 13 figures.
    Given set of poker cards, can pick any 1 card as 1st card.
    Then, except for 1st card, pick card that has same suit or figure.
    Return maximum number of cards that can be picked.
    Ex. Input: [['H','3'],['H','4'],['S','4'],['D','5'],['D','1']]
        Output: 3 -> [['H','3'],['H','4'],['S','4']]

    DFS + backtracking, visit each card & see longest path, store max

    Time: O(2^n)
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
    int getPokerHand(vector<vector<char>>& cards) {
        int result = INT_MIN;
        for (int i = 0; i < cards.size(); i++) {
            vector<char> card = cards[i];

            vector<vector<char>> path = {card};
            int curr = 0;

            set<vector<char>> visited;
            visited.insert(card);

            dfs(card, visited, path, curr, cards);
            result = max(result, curr);
        }
        return result;
    }
private:
    void dfs(vector<char>& card, set<vector<char>>& visited,
        vector<vector<char>>& path, int& curr, vector<vector<char>>& cards) {
        
        vector<vector<char>> neighbors = getNeighbors(card, visited, cards);
        if (neighbors.empty()) {
            curr = max(curr, (int) path.size());
            return;
        }

        for (int i = 0; i < neighbors.size(); i++) {
            vector<char> neighbor = neighbors[i];

            visited.insert(neighbor);
            path.push_back(neighbor);

            dfs(neighbor, visited, path, curr, cards);

            visited.erase(neighbor);
            path.pop_back();
        }
    }

    vector<vector<char>> getNeighbors(vector<char>& start,
        set<vector<char>> visited, vector<vector<char>>& cards) {

            vector<vector<char>> neighbors;
            for (int i = 0; i < cards.size(); i++) {
                vector<char> card = cards[i];
                if (start != card && visited.find(card) == visited.end()) {
                    if (start[0] == card[0] || start[1] == card[1]) {
                        neighbors.push_back(card);
                    }
                }
            }
            return neighbors;
        }
};

int main() {
    vector<vector<char>> cards1 = {
        {'H', '3'}, {'H', '4'}, {'S', '4'}, {'D', '5'}, {'D', '1'}
    };
    vector<vector<char>> cards2 = {
        {'H', '2'}, {'H', '3'}, {'H', '4'}, {'S', '4'}, {'D', '5'}, {'D', '1'}
    };
    vector<vector<char>> cards3 = {
        {'H', '2'}, {'H', '3'}, {'H', '4'}, {'S', '2'}, {'D', '3'}, {'C', '4'},
        {'C', '7'}
    };
    Solution* obj = new Solution();
    cout << obj->getPokerHand(cards1) << " "
         << obj->getPokerHand(cards2) << " "
         << obj->getPokerHand(cards3) << endl;

    return 0;
}
