/*
    Given 2D int array where paint[i] = [iStart, iEnd]:
    Need to paint these areas, painting multiple times uneven
    Return an int array w/ amount of NEW area painted on ith day
    Ex. paint = [[1,4],[4,7],[5,8]] -> [3,3,1], (4-1,7-4,8-7)

    Determine entire range in ordered set, then loop thru days & track counts

    Time: O(n log n)
    Space: O(n)
*/

class Solution {
public:
    vector<int> amountPainted(vector<vector<int>>& paint) {
        int minStart = INT_MAX;
        int maxEnd = INT_MIN;
        for (int i = 0; i < paint.size(); i++) {
            minStart = min(minStart, paint[i][0]);
            maxEnd = max(maxEnd, paint[i][1]);
        }
        
        set<int> s;
        for (int i = minStart; i < maxEnd; i++) {
            s.insert(i);
        }
        
        vector<int> result;
        
        for (int i = 0; i < paint.size(); i++) {
            int start = paint[i][0];
            int end = paint[i][1];
            int count = 0;
            
            auto it = s.lower_bound(start);
            while (it != s.end() && *it < end) {
                it = s.erase(it);
                count++;
            }
            
            result.push_back(count);
        }
        
        return result;
    }
};
