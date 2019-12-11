#include <stdio.h>

#include <iostream>
#include <vector>

using namespace std;

void findRegions(vector<vector<int>>& matrix, int& result, int i, int j, int m, int n) {
    if (i < 0 || i >= m || j < 0 || j >= n || matrix[i][j] == 0) {
        return;
    }
    matrix[i][j] = 0;
    result++;
    findRegions(matrix, result, i - 1, j, m, n);
    findRegions(matrix, result, i + 1, j, m, n);
    findRegions(matrix, result, i, j - 1, m, n);
    findRegions(matrix, result, i, j + 1, m, n);
    findRegions(matrix, result, i - 1, j - 1, m, n);
    findRegions(matrix, result, i - 1, j + 1, m, n);
    findRegions(matrix, result, i + 1, j - 1, m, n);
    findRegions(matrix, result, i + 1, j + 1, m, n);
}

int largestRegion(vector<vector<int>>& matrix) {
    if (matrix.empty()) {
        return 0;
    }
    int m = matrix.size();
    int n = matrix[0].size();
    int largest = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 1) {
                int result = 0;
                findRegions(matrix, result, i, j, m, n);
                if (result > largest) {
                    largest = result;
                }
            }
        }
    }
    return largest;
}

int main()
{
    vector<vector<int>> matrix = {
        {0, 0, 1, 1, 0},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 0, 0, 1}
    };
    int test = largestRegion(matrix);
    cout << test << endl;

    return 0;
}
