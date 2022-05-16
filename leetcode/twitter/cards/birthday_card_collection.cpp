/*
    HackerCards is a trendy new card game. Each type of HackerCard has
    a distinct ID # >= 1, and cost of each card = ID #.
    Leanne already has a collection started. For her bday, Mike wants
    to buy her as many cards as he can, but they must cost <= his
    budget. Wants to buy 1 of each cards she doesn't already have. If
    he has to make a choice among several, chooses lowest cost option.
    Determine which cards to buy.
    Ex. collection = [1,3,4], d = 7 -> [2,5], doesn't have + in budget

    Hash set to track owned cards, add from lowest until over budget

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
    vector<int> hackerCards(vector<int>& collection, int d) {
        unordered_set<int> s(collection.begin(), collection.end());

        int sum = 0;
        vector<int> result;

        for (int i = 1; i <= d; i++) {
            if (s.find(i) != s.end()) {
                continue;
            }
            if (sum + i > d) {
                break;
            }
            sum += i;
            result.push_back(i);
        }

        return result;
    }
};

int main() {
    vector<int> collection = {1, 3, 4};
    int d = 7;
    Solution* obj = new Solution();
    vector<int> result = obj->hackerCards(collection, d);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
