class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < points.size(); i++) {
            int distance = pow(points[i][0], 2) + pow(points[i][1], 2);
            pq.push(make_pair(distance, i));
        }
        vector<vector<int>> result;
        for (int i = 0; i < K; i++) {
            int index = pq.top().second;
            result.push_back(points[index]);
            pq.pop();
        }
        return result;
    }
};
