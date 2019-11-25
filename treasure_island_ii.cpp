#include <stdio.h>

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int shortestPath(vector<vector<char>> islands) {
    if (islands.empty() || islands[0].empty()) {
        return -1;
    }
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int row = islands.size();
    int col = islands[0].size();
    queue<vector<int>> q;
    int steps = 1;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (islands[i][j] == 'S') {
                q.push({i, j});
                islands[i][j] = 'D';
            }
        }
    }
    while (!q.empty()) {
        for (int i = 0; i < q.size(); i++) {
            vector<int> pos = q.front();
            q.pop();
            for (int i = 0; i < dirs.size(); i++) {
                int x = pos[0] + dirs[i][0];
                int y = pos[1] + dirs[i][1];
                if (x < 0 || x >= row || y < 0 || y >= col || islands[x][y] == 'D') {
                    continue;
                }
                if (islands[x][y] == 'X') {
                    return steps;
                }
                q.push({x, y});
                islands[x][y] = 'D';
            }
        }
        steps++;
    }
    return -1;
}

int main()
{
    vector<vector<char>> islands = {
        {'S', 'O', 'O', 'S', 'S'},
        {'D', 'O', 'D', 'O', 'D'},
        {'O', 'O', 'O', 'O', 'X'},
        {'X', 'D', 'D', 'O', 'O'},
        {'X', 'D', 'D', 'D', 'O'}
    };
    cout << shortestPath(islands) << endl;

    return 0;
}
