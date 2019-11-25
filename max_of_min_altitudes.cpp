#include <stdio.h>

#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int maxOfMinAltitudes(vector<vector<int>>& matrix) {
    if (matrix.empty()) {
        return 0;
    }
    int r = matrix.size();
    int c = matrix[0].size();
    for (int i = 2; i < r; i++) {
        matrix[i][0] = min(matrix[i-1][0], matrix[i][0]);
    }
    for (int i = 2; i < c; i++) {
        matrix[0][i] = min(matrix[0][i-1], matrix[0][i]);
    }
    for (int i = 1; i < r; i++) {
        for (int j = 1; j < c; j++) {
            if (i == r - 1 && j == c - 1) {
                matrix[i][j] = max(matrix[i-1][j], matrix[i][j-1]);
            } else {
                matrix[i][j] = max(min(matrix[i-1][j], matrix[i][j]), min(matrix[i][j-1], matrix[i][j]));
            }
        }
    }
    return matrix[r-1][c-1];
}

int main()
{
    vector<vector<int>> matrix1 = {{5, 1}, {4, 5}};
    vector<vector<int>> matrix2 = {{1, 2, 3}, {4, 5, 1}};
    int test1 = maxOfMinAltitudes(matrix1);
    int test2 = maxOfMinAltitudes(matrix2);
    cout << "test1: " << test1 << endl;
    cout << "test2: " << test2 << endl;

    return 0;
}
