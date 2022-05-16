/*
    Design a deck of cards. Add a shuffle() method.

    Time: O(n)
    Space: O(n)
*/

#include <stdio.h>

#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

enum Suit {
    SPADES, CLUBS, HEARTS, DIAMONDS
};

enum Face {
    TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
    JACK, QUEEN, KING, ACE
};

class Card {
public:
    Card() {}
    Card(Suit suit, Face face) : suit(suit), face(face) {}
    Suit getSuit() {
        return suit;
    }
    Face getFace() {
        return face;
    }
    void setSuit(Suit s) {
        suit = s;
    }
    void setFace(Face f) {
        face = f;
    }
private:
    Suit suit;
    Face face;
};

class Deck {
public:
    Deck() {
        cards.resize(SUITS * FACES);
        for (int i = 0; i < SUITS; i++) {
            for (int j = 0; j < FACES; j++) {
                int index = i * FACES + j;
                cards[index].setSuit((Suit) i);
                cards[index].setFace((Face) j);
            }
        }
    }

    void shuffle() {
        int length = cards.size();
        srand(time(NULL));
        while (length > 0) {
            int index = rand() % length;
            swap(cards[index], cards[length]);
            length--;
        }
    }

    Card drawTop() {
        Card firstCard = cards[0];
        cards.erase(cards.begin());
        return firstCard;
    }

    Card drawRandom() {
        int length = cards.size();
        srand(time(NULL));
        int index = rand() % length;
        Card card = cards[index];
        cards.erase(cards.begin() + index);
        return card;
    }

    vector<vector<Card>> dealCards(int numCards, int numPlayers) {
        int length = cards.size();
        if (numCards * numPlayers > length) {
            return {};
        }
        vector<vector<Card>> result;
        for (int i = 0; i < numPlayers; i++) {
            vector<Card> curr;
            for (int j = 0; j < numCards; j++) {
                curr.push_back(cards[0]);
                cards.erase(cards.begin());
            }
            result.push_back(curr);
        }
        return result;
    }

    void reset() {
        cards.resize(SUITS * FACES);
        for (int i = 0; i < SUITS; i++) {
            for (int j = 0; j < FACES; j++) {
                int index = i * FACES + j;
                cards[index].setSuit((Suit) i);
                cards[index].setFace((Face) j);
            }
        }
    }

    void print() {
        cout << "Cards in Deck: " << cards.size() << endl;
        for (int i = 0; i < cards.size(); i++) {
            cout << cards[i].getSuit() << ":"
                 << cards[i].getFace() << " ";
        }
        cout << endl << endl;
    }
private:
    const static int SUITS = 4;
    const static int FACES = 13;
    vector<Card> cards;
};

int main() {
    Deck* obj = new Deck();
    obj->print();
    obj->shuffle();
    obj->print();

    obj->drawTop();
    obj->print();
    obj->drawRandom();
    obj->print();

    obj->reset();
    obj->print();
    obj->shuffle();
    vector<vector<Card>> result = obj->dealCards(3, 5);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j].getSuit() << ":"
                 << result[i][j].getFace() << " ";
        }
        cout << endl;
    }
    cout << endl;
    obj->print();

    return 0;
}
