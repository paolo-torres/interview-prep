#include <stdio.h>

#include <iostream>
#include <vector>

using namespace std;

void findComponents(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int& result, int value, int i, int j, int m, int n) {
    if (i < 0 || i >= m || j < 0 || j >= n || matrix[i][j] != value || visited[i][j] == true) {
        return;
    }
    visited[i][j] = true;
    result++;
    findComponents(matrix, visited, result, matrix[i][j], i - 1, j, m, n);
    findComponents(matrix, visited, result, matrix[i][j], i + 1, j, m, n);
    findComponents(matrix, visited, result, matrix[i][j], i, j - 1, m, n);
    findComponents(matrix, visited, result, matrix[i][j], i, j + 1, m, n);
}

int largestComponent(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    int largest = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                int result = 0;
                findComponents(matrix, visited, result, matrix[i][j], i, j, m, n);
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
        {1, 4, 4, 4, 4, 3, 3, 1},
        {2, 1, 1, 4, 3, 3, 1, 1},
        {3, 2, 1, 1, 2, 3, 2, 1},
        {3, 3, 2, 1, 2, 2, 2, 2},
        {3, 1, 3, 1, 1, 4, 4, 4},
        {1, 1, 3, 1, 1, 4, 4, 4}
    };
    int test = largestComponent(matrix);
    cout << test << endl;

    return 0;
}
