/*
    Given cards, a pair of cards are matching if same value
    Return min # of consecutive cards to pick up to have a
    pair of matching cards among the picked cards
    Ex. cards = [3,4,2,3,4,7] -> 4, [3,4,2,3] has matching 3

    Same as Longest Substr w/o Repeating Chars, except min

    Time: O(n)
    Space: O(n)
*/

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_set<int> s;
        
        int i = 0;
        int j = 0;
        
        int result = INT_MAX;
        
        while (j < cards.size()) {
            if (s.find(cards[j]) == s.end()) {
                s.insert(cards[j]);
                j++;
            } else {
                result = min(result, j - i + 1);
                s.erase(cards[i]);
                i++;
            }
        }
        
        return result == INT_MAX ? -1 : result;
    }
};
