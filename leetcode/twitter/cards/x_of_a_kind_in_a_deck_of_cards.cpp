/*
    Deck of cards, return true if can split into groups where:
        - Each group has exactly X cards, where X >= 2
        - All the cards in each group have the same integer
    Ex. deck = [1,2,3,4,4,3,2,1] -> true, [1,1],[2,2],[3,3],[4,4]

    If c cards of number i, must be broken down into X cards each:
    c % X == 0 for all i
    Thus, X must divide GCD of c, if this GCD is >= 2, X = g

    Time: O(n log^2 n) -> n = number of cards, log^2 n for GCD
    Space: O(n)
*/

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        // {value -> count}
        unordered_map<int, int> m;
        for (int i = 0; i < deck.size(); i++) {
            m[deck[i]]++;
        }
        
        int result = 0;
        for (auto it = m.begin(); it != m.end(); it++) {
            result = gcd(result, it->second);
        }
        return result >= 2;
    }
private:
    int gcd(int x, int y) {
        return x == 0 ? y : gcd(y % x, x);
    }
};
