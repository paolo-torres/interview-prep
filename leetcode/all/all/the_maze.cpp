#include <stdio.h>

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool hasPath(vector<vector<int>>& maze, vector<int> start, vector<int> dest) {
    int i = maze.size();
    int j = maze[0].size();
    bool visited[i][j] = {false};
    vector<vector<int>> dirs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    queue<vector<int>> q;
    q.push(start);
    visited[start[0]][start[1]] = true;
    while (!q.empty()) {
        vector<int> s = q.front();
        q.pop();
        if (s[0] == dest[0] && s[1] == dest[1]) {
            return true;
        }
        for (int i = 0; i < dirs.size(); i++) {
            int x = s[0] + dirs[i][0];
            int y = s[1] + dirs[i][1];
            while (x >= 0 && y >= 0 && x < maze.size() && y < maze[0].size() && maze[x][y] == 0) {
                x += dirs[i][0];
                y += dirs[i][1];
            }
            if (!visited[x-dirs[i][0]][y-dirs[i][1]]) {
                q.push({x-dirs[i][0], y-dirs[i][1]});
                visited[x-dirs[i][0]][y-dirs[i][1]] = true;
            }
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> myMaze = {
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0},
        {1, 1, 0, 1, 1},
        {0, 0, 0, 0, 0}
    };
    vector<int> start1 = {0, 4};
    vector<int> dest1 = {4, 4};
    vector<int> start2 = {0, 4};
    vector<int> dest2 = {3, 2};
    cout << "Example 1: " << hasPath(myMaze, start1, dest1) << endl;
    cout << "Example 2: " << hasPath(myMaze, start2, dest2) << endl;

    return 0;
}
