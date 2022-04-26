/*
    Given cards w/ points, can either take from beginning or end
    Have to take exactly k cards, return max score can obtain
    Ex. cardPoints = [1,2,3,4,5,6,1], k = 3 -> 12 (1 + 6 + 5)

    Chose k cards at front, then choose k - i cards at back, store max

    Time: O(k)
    Space: O(1)
*/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        
        int frontScore = 0;
        int rearScore = 0;
        
        for (int i = 0; i < k; i++) {
            frontScore += cardPoints[i];
        }
        
        // take all k cards from the start
        int result = frontScore;
        
        // take i from the start and k - i from the end
        for (int i = k - 1; i >= 0; i--) {
            rearScore += cardPoints[n - (k - i)];
            frontScore -= cardPoints[i];
            int currScore = frontScore + rearScore;
            result = max(result, currScore);
        }
        
        return result;
    }
};
