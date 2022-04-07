// Start from end, iterate backwards, track max

// Time: O(n)
// Space: O(n)

class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int maxHeight = 0;
        vector<int> result;
        
        for (int i = heights.size() - 1; i >= 0; i--) {
            if (heights[i] > maxHeight) {
                result.push_back(i);
                maxHeight = heights[i];
            }
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};
