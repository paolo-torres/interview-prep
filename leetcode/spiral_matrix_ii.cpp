class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, 0));
        if (n == 0) {
            return result;
        }
        int value = 1;
        int left = 0;
        int right = n - 1;
        int top = 0;
        int bottom = n - 1;
        while (left <= right && top <= bottom) {
            for (int i = left; i <= right; i++) {
                result[top][i] = value;
                value++;
            }
            top++;
            for (int i = top; i <= bottom; i++) {
                result[i][right] = value;
                value++;
            }
            right--;
            for (int i = right; i >= left; i--) {
                result[bottom][i] = value;
                value++;
            }
            bottom--;
            for (int i = bottom; i >= top; i--) {
                result[i][left] = value;
                value++;
            }
            left++;
        }
        return result;
    }
};
