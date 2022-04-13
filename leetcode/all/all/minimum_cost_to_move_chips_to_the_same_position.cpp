// All evens can be moved to pos 0, odds to pos 1, for free
// There's only cost from even -> odd, or odd -> even
// Less cost to move smaller pile to larger, so take min
// Works bc now all beside each other (cost 1)

// Time: O(n)
// Space: O(1)

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int evenCount = 0;
        int oddCount = 0;
        
        for (int i = 0; i < position.size(); i++) {
            if (position[i] % 2 == 0) {
                evenCount++;
            } else {
                oddCount++;
            }
        }
        
        return min(evenCount, oddCount);
    }
};
