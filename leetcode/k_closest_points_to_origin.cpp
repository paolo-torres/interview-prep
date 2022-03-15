// Time: O(n log k)
// Space: O(k)

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, vector<int>>> pq;
        for (int i = 0; i < points.size(); i++) {
            double distance = sqrt(pow(points[i][0], 2) + pow(points[i][1], 2));
            pq.push({distance, points[i]});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        
        vector<vector<int>> result;
        while(!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        
        return result;
    }
};
