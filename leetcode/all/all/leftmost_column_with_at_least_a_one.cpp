// Binary search -> optimize w/ start at top right, move only left & down

/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

// // Time: O(m log n)
// // Space: O(1)

// class Solution {
// public:
//     int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
//         vector<int> size = binaryMatrix.dimensions();
//         int result = INT_MAX;
        
//         for (int i = 0; i < size[0]; i++) {
//             int low = 0;
//             int high = size[0] - 1;
//             while (low < high) {
//                 int mid = low + (high - low) / 2;
//                 if (binaryMatrix.get(i, mid) == 0) {
//                     low = mid + 1;
//                 } else {
//                     high = mid;
//                 }
//             }
//             if (binaryMatrix.get(i, low) == 1) {
//                 result = min(result, low);
//             }
//         }
        
//         if (result == INT_MAX) {
//             return -1;
//         }
//         return result;
//     }
// };

// Time: O(m + n)
// Space: O(1)

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> size = binaryMatrix.dimensions();
        
        int row = 0;
        int col = size[1] - 1;
        
        while (row < size[0] && col >= 0) {
            if (binaryMatrix.get(row, col) == 0) {
                row++;
            } else {
                col--;
            }
        }
        
        if (col == size[1] - 1) {
            return -1;
        }
        return col + 1;
    }
};
