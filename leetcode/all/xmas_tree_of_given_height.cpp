#include <stdio.h>

#include <iostream>
#include <vector>

using namespace std;

vector<vector<string>> christmasTree(int height) {
    int space = 0;
    vector<string> temp;
    vector<vector<string>> result;
    while (height > 0) {
        int tree = 2 * height - 1;
        for (int i = 0; i < space; i++) {
            temp.push_back(" ");
        }
        for (int i = 0; i < tree; i++) {
            temp.push_back("#");
        }
        for (int i = 0; i < space; i++) {
            temp.push_back(" ");
        }
        result.insert(result.begin(), temp);
        temp.clear();
        space++;
        height--;
    }
    return result;
}

int main()
{
    int height = 5;
    vector<vector<string>> result = christmasTree(height);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[0].size(); j++) {
            cout << result[i][j];
        }
        cout << endl;
    }

    return 0;
}
