/*
    Initially, each card placed on table such that front # facing up
    May flip over any # of cards, after flipping, an integer is good if
    it is facing down on some card and not facing up on any other
    Return minimum possible good integers after flipping cards
    Ex. fronts = [1,2,4,4,7], backs = [1,3,4,1,3] -> 2

    If card has same # on both front & back, can't possibly be good
    For the rest, for the min, can always find a way to flip the others
    to NOT be this number

    Time: O(n)
    Space: O(n)
*/

class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        int n = fronts.size();
        
        unordered_set<int> s;
        for (int i = 0; i < n; i++) {
            if (fronts[i] == backs[i]) {
                s.insert(fronts[i]);
            }
        }
        
        int result = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            if (s.find(fronts[i]) == s.end()) {
                result = min(result, fronts[i]);
            }
            if (s.find(backs[i]) == s.end()) {
                result = min(result, backs[i]);
            }
        }
        
        return result == INT_MAX ? 0 : result;
    }
};
