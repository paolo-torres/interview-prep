/*
    Given deck of cards, do the following until all cards revealed:
        1. Take top card of deck, reveal it, and take out of deck
        2. If there's still cards, then put next top card to bottom
        3. If there's still cards, go back to step 1, else stop
    Return an ordering of the deck that would reveal cards in increasing order
    Ex. deck = [17,13,11,2,3,5,7] -> [2,13,3,11,5,17,7]

    Sort array (our desired sequence), build result array, pick top, push top

    Time: O(n log n)
    Space: O(n)
*/

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        // [2,3,5,7,11,13,17]
        sort(deck.begin(), deck.end());
        
        queue<int> q;
        // [0,1,2,3,4,5,6]
        for (int i = 0; i < n; i++) {
            q.push(i);
        }
        
        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            // deck[0] = 2 -> result[0] = 2
            int top = q.front();
            q.pop();
            result[top] = deck[i];
            // put result[1] to the bottom
            top = q.front();
            q.pop();
            q.push(top);
        }
        return result;
    }
};
