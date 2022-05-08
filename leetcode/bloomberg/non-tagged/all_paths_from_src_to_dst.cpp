/*
    You have flights, e.g.,
    A -> B
    B -> C, D
    C -> E
    D -> E
    Implement 2 methods. 1 to add a new start and end location. 1 to
    print all locations from a starting destination, e.g., print all
    possible travel methods from A to E.

    DFS + backtracking + graph, same as All Paths From Source To Target

    Time: O(n x 2^n) -> n = # of nodes, 2^n = backtracking either pick or don't pick node
    Space: O(n x 2^n) -> n from recursive call stack, 2^n from storing paths
*/

#include <stdio.h>

#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    void addStop(char source, char destination) {
        m[source].push_back(destination);
    }

    vector<vector<char>> getPaths(char source, char destination) {
        unordered_set<char> visited;
        visited.insert(source);

        vector<char> path = {source};
        vector<vector<char>> result;

        dfs(source, destination, path, visited, result);

        return result;
    }
private:
    // {source -> list of all destinations}
    unordered_map<char, vector<char>> m;

    void dfs(char source, char destination, vector<char>& path,
        unordered_set<char>& visited, vector<vector<char>>& result) {
        if (path.back() == destination) {
            result.push_back(path);
            return;
        }

        for (int i = 0; i < m[source].size(); i++) {
            char city = m[source][i];
            if (visited.find(city) != visited.end()) {
                continue;
            }

            path.push_back(city);
            visited.insert(city);

            dfs(city, destination, path, visited, result);

            visited.erase(city);
            path.pop_back();
        }
    }
};

int main() {
    Solution* obj = new Solution();
    obj->addStop('A', 'B');
    obj->addStop('A', 'P');
    obj->addStop('P', 'E');
    obj->addStop('B', 'C');
    obj->addStop('B', 'D');
    obj->addStop('C', 'G');
    obj->addStop('C', 'A');
    obj->addStop('G', 'E');
    obj->addStop('C', 'E');
    obj->addStop('D', 'E');
    obj->addStop('E', 'P');

    vector<vector<char>> result = obj->getPaths('A', 'E');
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
