/*
    Given matrix where each row & col sorted, return kth smallest
    Ex. matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8 -> 13

    Max heap top kth smallest -> optimize w/ binary search:
    Find smallest ans in range [min...max] where countLessOrEqual(ans) >= k

    Time: O(n^2 log k) -> optimize to O((n + n) log (max - min))
    Space: O(1)
*/

// class Solution {
// public:
//     int kthSmallest(vector<vector<int>>& matrix, int k) {
//         priority_queue<int> pq;
//         for (int i = 0; i < matrix.size(); i++) {
//             for (int j = 0; j < matrix[0].size(); j++) {
//                 pq.push(matrix[i][j]);
//                 if (pq.size() > k) {
//                     pq.pop();
//                 }
//             }
//         }
//         return pq.top();
//     }
// };

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        
        int low = matrix[0][0];
        int high = matrix[n - 1][n - 1];
        
        int result = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (countLessOrEqual(matrix, mid) >= k) {
                result = mid;
                // look for smaller value in left side
                high = mid - 1;
            } else {
                // look for larger value in right side
                low = mid + 1;
            }
        }
        
        return result;
    }
private:
    int countLessOrEqual(vector<vector<int>>& matrix, int x) {
        int count = 0;
        // start at rightmost col
        int j = matrix[0].size() - 1;
        for (int i = 0; i < matrix.size(); i++) {
            // decrease col until matrix[i][j] <= x
            while (j >= 0 && matrix[i][j] > x) {
                j--;
            }
            count += j + 1;
        }
        return count;
    }
};
