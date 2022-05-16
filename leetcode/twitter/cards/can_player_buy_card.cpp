/*
    Given card with cost in terms of tokens. Ex, to buy Card A, need 3
    blue tokens & 2 green tokens. Tokens can be red, green, blue,
    black, or white.
    Player holding some tokens. Ex. 4 blue & 2 green, then Player can
    buy Card A.
    Write method that returns true if Player can buy card or not.
    Ex. cost = 2 white, 1 black, 4 blue
        if Player has 2 white, 2 black, 4 blue, return true
        if Player has 2 white, 2 green, 4 blue, return false

    Time: O(1)
    Space: O(1)
*/

#include <stdio.h>

#include <iostream>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct Tokens {
    int red, green, blue, black, white;
    Tokens() : red(0), green(0), blue(0), black(0), white(0) {}
    Tokens(int red, int green, int blue, int black, int white) :
        red(red), green(green), blue(blue), black(black),
        white(white) {}
};

class Solution {
public:
    bool canPlayerBuyCard(Tokens& player, Tokens& cost) {
        return player.red >= cost.red
            && player.green >= cost.green
            && player.blue >= cost.blue
            && player.black >= cost.black
            && player.white >= cost.white;
    }
};

int main() {
    Tokens card(0, 0, 4, 1, 2);
    Tokens player1(0, 0, 4, 2, 2);
    Tokens player2(0, 2, 4, 0, 2);

    Solution* obj = new Solution();
    cout << obj->canPlayerBuyCard(player1, card) << endl;
    cout << obj->canPlayerBuyCard(player2, card) << endl;

    return 0;
}
