// Given 2 points on a diagonal, can determine area
// Hash map {x value -> set of y values w/ same x value}

// Time: O(n^2)
// Space: O(n)

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, unordered_set<int>> m;
        for (int i = 0; i < points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];
            m[x].insert(y);
        }
        
        int result = INT_MAX;
        
        for (int i = 0; i < points.size() - 1; i++) {
            for (int j = i + 1; j < points.size(); j++) {
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                
                // must form diagonal of a rectangle, skip if not
                if (x1 == x2 || y1 == y2) {
                    continue;
                }
                
                // matching diagonal must exist in hash map to make rectangle
                if (m[x1].find(y2) != m[x1].end() && m[x2].find(y1) != m[x2].end()) {
                    int area = abs(x2 - x1) * abs(y2 - y1);
                    result = min(result, area);
                }
            }
        }
        
        if (result == INT_MAX) {
            return 0;
        } else {
            return result;
        }
    }
};
