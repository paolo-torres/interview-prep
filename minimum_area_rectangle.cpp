class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, unordered_set<int>> m;
        for (int i = 0; i < points.size(); i++) {
            m[points[i][0]].insert(points[i][1]);
        }
        int result = INT_MAX;
        for (int i = 0; i < points.size() - 1; i++) {
            for (int j = i + 1; j < points.size(); j++) {
                int xOne = points[i][0];
                int yOne = points[i][1];
                int xTwo = points[j][0];
                int yTwo = points[j][1];
                if (xOne == xTwo || yOne == yTwo) {
                    continue;
                }
                if (m[xOne].find(yTwo) != m[xOne].end() && m[xTwo].find(yOne) != m[xTwo].end()) {
                    int area = abs(xTwo - xOne) * abs(yTwo - yOne);
                    if (area < result) {
                        result = area;
                    }
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
