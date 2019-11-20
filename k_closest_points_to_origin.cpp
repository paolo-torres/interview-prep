class Solution {
private:
    int getDist(int x, int y) {
        return x * x + y * y;
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> result;
        if (points.size() == K) {
            return points;
        }
        int curDist = 0;
        int maxDist = INT_MAX;
        int count = 0;
        multimap<int, vector<int>> m;
        for (int i = 0; i < points.size(); i++) {
            curDist = getDist(points[i][0], points[i][1]);
            if (curDist < maxDist || count < K) {
                if (m.size() != 0 && count >= K) {
                    m.erase(prev(m.end()));
                    count--;
                }
                m.insert({curDist, {points[i][0], points[i][1]}});
                auto it = prev(m.end());
                maxDist = it->first;
                count++;
            }
        }
        for (auto it = m.begin(); it != m.end(); ++it) {
            result.push_back(it->second);
        }
        return result;
    }
};
