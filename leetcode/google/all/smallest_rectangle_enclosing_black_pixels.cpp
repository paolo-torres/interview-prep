/*
    Binary matrix, 0 = white, 1 = black, black pixels are connected
    There's only 1 black region, given 2 ints x & y where (x,y) is black:
    Return smallest rectangular area that encloses all black pixels

    DFS -> binary search to "find existence of black pixel"

    Time: O(m x n) -> optimize to O(m log m + n log n) w/ binary search 
    Space: O(m x n) -> optimize to O(1)
*/

// class Solution {
// public:
//     int minArea(vector<vector<char>>& image, int x, int y) {
//         pair<int, int> xRange = {x, x};
//         pair<int, int> yRange = {y, y};
//         dfs(image, x, y, xRange, yRange);
//         return (xRange.second - xRange.first + 1) * (yRange.second - yRange.first + 1);
//     }
// private:
//     void dfs(vector<vector<char>>& image, int x, int y, pair<int, int>& xRange, pair<int, int>& yRange) {
//         if (x < 0 || x >= image.size() || y < 0 || y >= image[0].size() || image[x][y] == '0') {
//             return;
//         }
//         image[x][y] = '0';
//         xRange = {min(xRange.first, x), max(xRange.second, x)};
//         yRange = {min(yRange.first, y), max(yRange.second, y)};
//         dfs(image, x - 1, y, xRange, yRange);
//         dfs(image, x + 1, y, xRange, yRange);
//         dfs(image, x, y - 1, xRange, yRange);
//         dfs(image, x, y + 1, xRange, yRange);
//     }
// };

class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int top = getMinRow(image, 0, x);
        int bottom = getMaxRow(image, x, image.size() - 1);
        int left = getMinCol(image, 0, y);
        int right = getMaxCol(image, y, image[0].size() - 1);
        
        return (bottom - top + 1) * (right - left + 1);
    }
private:
    int getMinRow(vector<vector<char>>& image, int low, int high) {
        int result = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (blackInRow(image, mid)) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return result;
    }
    
    int getMaxRow(vector<vector<char>>& image, int low, int high) {
        int result = low;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (blackInRow(image, mid)) {
                result = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return result;
    }
    
    int getMinCol(vector<vector<char>>& image, int low, int high) {
        int result = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (blackInCol(image, mid)) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return result;
    }
    
    int getMaxCol(vector<vector<char>>& image, int low, int high) {
        int result = low;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (blackInCol(image, mid)) {
                result = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return result;
    }
    
    bool blackInRow(vector<vector<char>>& image, int row) {
        for (int j = 0; j < image[row].size(); j++) {
            if (image[row][j] == '1') {
                return true;
            }
        }
        return false;
    }
    
    bool blackInCol(vector<vector<char>>& image, int col) {
        for (int i = 0; i < image.size(); i++) {
            if (image[i][col] == '1') {
                return true;
            }
        }
        return false;
    }
};
