/*
    Given input of cards w/ suits {+, -, =}, values {A, B, C} and
    different counts [1 - 3], find a valid hand (any):
        - 3 cards
        - Suits all same or different
        - Values all same or different
        - Counts all same or different
    Ex. [+AA, -AA, +AA, -C, -B, +AA, -AAA, -A, =AA]
        [[+AA,+AA,+AA], [-A,-AA,-AAA]], [-C,-B,-A], [+AA,-AA,=AA]]

    1. Count the number of each type of card.
    2. For each card, iterate thru the number of types.
    3. Given 2 cards, can find 3rd one, ex. +B and -A -> =C.
        a. First 2 cards have diff types, so 3rd must be diff
        b. First 2 cards have diff values, so 3rd must be diff
        c. First 2 cards have same length, so 3rd must have same
    4. Look up all 3 cards in count map, if all exists, valid pair

    Time: O(n)
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

class Solution {
public:
    vector<string> getValidCardHands(vector<string>& cards) {
        unordered_set<char> types({'+', '-', '='});
        unordered_set<char> colors({'A', 'B', 'C'});
        unordered_set<int> counts({2, 3, 4});

        unordered_map<string, int> countOfCards;
        for (int i = 0; i < cards.size(); i++) {
            countOfCards[cards[i]]++;
        }

        for (auto card : cards) {
            for (auto type : types) {
                for (auto color : colors) {
                    for (auto count : counts) {
                        string secondCard = string(1, type);
                        for (int i = 1; i < count; i++) {
                            secondCard += color;
                        }
                        unordered_set<char> t = types;
                        unordered_set<char> cols = colors;
                        unordered_set<int> cnts = counts;
                        string thirdCard = getThirdCard(card,
                            secondCard, t, cols, cnts);
                        if (isPresent(countOfCards, card, secondCard,
                            thirdCard)) {
                            return {card, secondCard, thirdCard};
                        }
                    }
                }
            }
        }

        return {};
    }
private:
    string getThirdCard(string& firstCard, string& secondCard,
        unordered_set<char>& types, unordered_set<char>& colors,
        unordered_set<int>& counts) {
        
        char firstType = firstCard[0];
        char firstColor = firstCard[1];
        int firstLength = firstCard.size();

        char secondType = secondCard[0];
        char secondColor = secondCard[1];
        int secondLength = secondCard.size();

        char thirdType;
        char thirdColor;
        int thirdLength = 0;

        if (firstType == secondType) {
            thirdType = firstType;
        } else {
            types.erase(firstType);
            types.erase(secondType);
            thirdType = *types.begin();
        }

        if (firstColor == secondColor) {
            thirdColor = firstColor;
        } else {
            colors.erase(firstColor);
            colors.erase(secondColor);
            thirdColor = *colors.begin();
        }

        if (firstLength == secondLength) {
            thirdLength = firstLength;
        } else {
            counts.erase(firstLength);
            counts.erase(secondLength);
            thirdLength = *counts.begin();
        }

        string thirdCard = string(1, thirdType);
        for (int i = 1; i < thirdLength; i++) {
            thirdCard += thirdColor;
        }
        return thirdCard;
    }

    bool isPresent(unordered_map<string, int>& countOfCards,
        string& firstCard, string& secondCard, string& thirdCard) {
            if (firstCard == secondCard) {
                return countOfCards[firstCard] >= 3;
            }
            return countOfCards[firstCard] >= 1
                && countOfCards[secondCard] >= 1
                && countOfCards[thirdCard] >= 1;
    }
};

int main() {
    vector<string> cards = {
        "+AA", "-AA", "+AA", "-C", "-B", "+AA", "-AAA", "-A", "=AA"
    };
    Solution* obj = new Solution();
    vector<string> result = obj->getValidCardHands(cards);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
