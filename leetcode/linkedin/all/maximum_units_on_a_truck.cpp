/*
    Given 2D array boxTypes, where boxTypes[i] = [# of boxes, # of units/box]
    and given truckSize, return max total # of units can be put on truck
    Ex. boxTypes = [[1,3],[2,2],[3,1]], truckSize = 4 -> 8, 1x3 + 2x2 + 1x1 = 8

    Counting sort, maintain # units/box -> # boxes, greedy fit as much as we can

    Time: O(n)
    Space: O(n)
*/

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();
        vector<int> count(1001);
        for (int i = 0; i < n; i++) {
            count[boxTypes[i][1]] += boxTypes[i][0];
        }
        
        int result = 0;
        
        for (int units = 1000; units > 0; units--) {
            if (count[units] > 0) {
                int maxFit = min(count[units], truckSize);
                result += units * maxFit;
                truckSize -= maxFit;
                if (truckSize == 0) {
                    return result;
                }
            }
        }
        
        return result;
    }
};
