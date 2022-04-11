#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

const vector<vector<const char> > maze {
    {'1', '1', '1', '1', '0', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '0', '1', '1', '1', '1', '1', '1'},
    {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
    {'0', '0', '0', '0', '0', '1', '1', '1', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1'},
    {'1', '1', 'B', '0', '0', '0', '1', '1', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1'},
    {'1', '1', '1', '0', '0', '0', '1', '1', '0', '0', '0', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1'},
    {'1', '1', '1', '1', '1', '1', '1', '1', '0', '0', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', 'A', '1'},
    {'1', '1', '1', '1', '1', '1', '1', '1', '0', '0', '0', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1'},
    {'0', '0', '0', '0', '0', '0', '0', '1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
    {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0'},
    {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '0'},
    {'1', '1', '1', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '1', '1', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0'},
    {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '0', '0', '1', '1', '1', '1', '0', '0', '0', '0'},
    {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '0', '0', '1', '0', '1', '1', '0', '1', '1', '0'},
    {'1', '1', 'S', '1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '0', '1', '0', '1', '1', '0', '1', '1', '1'},
    {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '0', '1', '0', '1', '1', '0', '1', '1', '1'},
    {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '0', '1', '1', '1'},
    {'1', '1', '0', '0', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '0', '1', '1', '1'},
    {'1', '1', '0', '0', '0', '1', '0', '0', '1', '1', '0', '0', '0', '1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1'},
    {'1', '1', '0', '1', '1', '1', '0', '0', '1', '1', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '1'},
    {'0', '0', '0', '1', '1', '1', '0', '0', '1', '1', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '1', '1', '1'},
    {'0', '0', '0', '1', '1', '1', '0', '0', '1', '1', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '1', '1', '1', '1', '1'},
    {'1', '1', '1', '1', '1', '1', '0', '0', '1', '1', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '1', '1', '1', '1', '1'},
    {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '1', '1', '1', '1', '1'},
    {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '0', '1', '1', '1', '1', '1'},
    {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}
};

vector<vector<int> > tracePath(map<vector<int>, vector<vector<int>> > &m, 
    int &cost, int iStart, int jStart, int iEnd, int jEnd) {
    vector<vector<int> > path; 
    int iTrace = iEnd;
    int jTrace = jEnd;
    path.push_back({iEnd, jEnd});
    ++cost;
    
    while (iTrace != iStart || jTrace != jStart) {
        for (auto it = m.begin(); it != m.end(); ++it) {
            for (int v = 0; v < it->second.size(); ++v) {
                if (iTrace == it->second[v][0] && jTrace == it->second[v][1]) {
                    iTrace = it->first[0];
                    jTrace = it->first[1];
                    path.push_back({iTrace, jTrace});
                    ++cost;
                }
            }
        }
    }

    reverse(path.begin(), path.end());
    return path;
}

bool isValid(int x, int y, vector<vector<bool> > &visited) {
    return x >= 0 && x < maze.size() && y >= 0 && y < maze[0].size() 
        && !visited[x][y] && maze[x][y] != '0';
}

void displayData(vector<vector<int> >& path, int &cost, int &nodes) {
    cout << "Path: ";
    for (int i = 0; i < path.size(); ++i) {
        cout <<  "(" << path[i][0] << ", " << path[i][1] << "), ";
    }
    cout << endl;
    cout << "Cost: " << cost << endl;
    cout << "Nodes: " << nodes << endl << endl;
}

bool bfs(vector<vector<int> > &path, map<vector<int>, vector<vector<int>> > &m, 
    int &cost, int &nodes, int i, int j, int iEnd, int jEnd) {
    vector<vector<bool> > visited(maze.size(), vector<bool>(maze[0].size(), false));
    vector<vector<int> > dirs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    queue<vector<int> > q;

    visited[i][j] = true;
    q.push({i, j});

    while (!q.empty()) {
        vector<int> s = q.front();
        q.pop();

        if (s[0] == iEnd && s[1] == jEnd) {
            path = tracePath(m, cost, i, j, iEnd, jEnd);
            return true;
        }

        for (int i = 0; i < dirs.size(); ++i) {
            int x = s[0] + dirs[i][0];
            int y = s[1] + dirs[i][1];

            if (isValid(x, y, visited)) {
                visited[x][y] = true;
                q.push({x, y});

                if (m.find({s[0], s[1]}) == m.end()) {
                    m.insert({{s[0], s[1]}, vector<vector<int>>()});
                }
                m[{s[0], s[1]}].push_back(q.back());

                ++nodes;
            }
        }
    }
    return false;
}

void applyBFS(int i, int j, int iEnd, int jEnd) {
    vector<vector<int> > path;
    map<vector<int>, vector<vector<int>> > m;
    int cost = 0;
    int nodes = 0;

    if (bfs(path, m, cost, nodes, i, j, iEnd, jEnd)) {
        displayData(path, cost, nodes);
    }
}

bool dfs(vector<vector<bool> > visited, vector<vector<int> > &path, 
    int &cost, int &nodes, int i, int j, int iEnd, int jEnd) {
    if (!visited[i][j]) {
        visited[i][j] = true;
        path.push_back({i, j});

        ++cost;
        ++nodes;

        if (i == iEnd && j == jEnd) {
            return true;
        }

        if (j > 0 && maze[i][j-1] != '0') {
            if (dfs(visited, path, cost, nodes, i, j - 1, iEnd, jEnd)) {
                return true;
            }
        }
        if (i > 0 && maze[i-1][j] != '0') {
            if (dfs(visited, path, cost, nodes, i - 1, j, iEnd, jEnd)) {
                return true;
            }
        }
        if (j < maze[0].size() - 1 && maze[i][j+1] != '0') {
            if (dfs(visited, path, cost, nodes, i, j + 1, iEnd, jEnd)) {
                return true;
            }
        }
        if (i < maze.size() && maze[i+1][j] != '0') {
            if (dfs(visited, path, cost, nodes, i + 1, j, iEnd, jEnd)) {
                return true;
            }
        }

        visited[i][j] = false;
        path.pop_back();

        --cost;
        --nodes;
    }
    return false;
}

void applyDFS(int i, int j, int iEnd, int jEnd) {
    vector<vector<bool> > visited(maze.size(), vector<bool>(maze[0].size(), false));
    vector<vector<int> > path;
    int cost = 0;
    int nodes = 0;

    if (dfs(visited, path, cost, nodes, i, j, iEnd, jEnd)) {
        displayData(path, cost, nodes);
    }

    for (auto &v: visited) {
        fill(v.begin(), v.end(), false);
    }

    path.clear();
    nodes = 0;
}

int getGCost(int iStart, int jStart, int i, int j) {
    return abs(i - iStart) + abs(j - jStart);
}

int getHCost(int i, int j, int iEnd, int jEnd) {
    return abs(i - iEnd) + abs(j - jEnd);
}

int getFCost(int iStart, int jStart, int i, int j, int iEnd, int jEnd) {
    return getGCost(iStart, jStart, i, j) + getHCost(i, j, iEnd, jEnd);
}

bool aStar(vector<vector<int> > &path, map<vector<int>, vector<vector<int>> > &m, 
    int &cost, int &nodes, int iStart, int jStart, int iEnd, int jEnd) {
    vector<vector<bool> > visited(maze.size(), vector<bool>(maze[0].size(), false));
    vector<vector<int> > dirs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, 
        greater<pair<int, pair<int, int>>> > pq;

    visited[iStart][jStart] = true;
    int fCost = getFCost(iStart, jStart, iStart, jStart, iEnd, jEnd);
    pq.push(make_pair(fCost, make_pair(iStart, jStart)));
    
    while (!pq.empty()) {
        pair<int, int> s = pq.top().second;
        pq.pop();

        if (s.first == iEnd && s.second == jEnd) {
            path = tracePath(m, cost, iStart, jStart, iEnd, jEnd);
            return true;
        }

        for (int i = 0; i < dirs.size(); ++i) {
            int x = s.first + dirs[i][0];
            int y = s.second + dirs[i][1];

            if (isValid(x, y, visited)) {
                visited[x][y] = true;
                int fCost = getFCost(iStart, jStart, x, y, iEnd, jEnd);

                pq.push(make_pair(fCost, make_pair(x, y)));

                if (m.find({s.first, s.second}) == m.end()) {
                    m.insert({{s.first, s.second}, vector<vector<int>>()});
                }
                m[{s.first, s.second}].push_back({x, y});

                ++nodes;
            }
        }
    }
    return false;
}

void applyAStar(int i, int j, int iEnd, int jEnd) {
    vector<vector<int> > path;
    map<vector<int>, vector<vector<int>> > m;
    int cost = 0;
    int nodes = 0;

    if (aStar(path, m, cost, nodes, i, j, iEnd, jEnd)) {
        displayData(path, cost, nodes);
    }
}

int main() {
    cout << "Breadth First Search" << endl << endl;

    applyBFS(13, 2, 5, 23);
    applyBFS(13, 2, 3, 2);
    applyBFS(24, 0, 0, 24);

    cout << "Depth First Search" << endl << endl;

    applyDFS(13, 2, 5, 23);
    applyDFS(13, 2, 3, 2);
    applyDFS(24, 0, 0, 24);

    cout << "A* Search" << endl << endl;

    applyAStar(13, 2, 5, 23);
    applyAStar(13, 2, 3, 2);
    applyAStar(24, 0, 0, 24);

    return 0;
}
