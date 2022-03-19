// // Time: O(n log k)
// // Space: O(k)

// class Solution {
// public:
//     vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
//         priority_queue<pair<double, vector<int>>> pq;
//         for (int i = 0; i < points.size(); i++) {
//             double distance = sqrt(pow(points[i][0], 2) + pow(points[i][1], 2));
//             pq.push({distance, points[i]});
//             if (pq.size() > k) {
//                 pq.pop();
//             }
//         }
        
//         vector<vector<int>> result;
//         while(!pq.empty()) {
//             result.push_back(pq.top().second);
//             pq.pop();
//         }
        
//         return result;
//     }
// };

// Quickselect, partition until pivot = k, left side all < k

// Time: O(n)
// Space: O(1)

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int low = 0;
        int high = points.size() - 1;
        int pivotIndex = points.size();
        
        while (pivotIndex != k) {
            pivotIndex = partition(points, low, high);
            if (pivotIndex < k) {
                low = pivotIndex;
            } else {
                high = pivotIndex - 1;
            }
        }
        
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
private:
    int partition(vector<vector<int>>& points, int low, int high) {
        vector<int> pivot = points[low + (high - low) / 2];
        int pivotDistance = getDistance(pivot);
        
        while (low < high) {
            if (getDistance(points[low]) >= pivotDistance) {
                swap(points[low], points[high]);
                high--;
            } else {
                low++;
            }
        }
        
        if (getDistance(points[low]) < pivotDistance) {
            low++;
        }
        return low;
    }
    
    int getDistance(vector<int>& point) {
        return pow(point[0], 2) + pow(point[1], 2);
    }
};
