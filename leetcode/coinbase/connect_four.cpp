/*
    Design Connect Four, implement winning horizontally, vertically,
    and diagonally, 2 player.

    Time: O(m x n)
    Space: O(m x n)
*/

#include <stdio.h>

#include <iostream>
#include <vector>

using namespace std;

class ConnectFour {
public:
    ConnectFour(int& r, int& c) {
        row = r;
        col = c;
        curr = 0;

        for (int i = 0; i < row; i++) {
            vector<int> newRow;
            for (int j = 0; j < col; j++) {
                newRow.push_back(0);
            }
            board.push_back(newRow);
        }

        for (int j = 0; j < col; j++) {
            rowIndex.push_back(0);
        }
    }

    void play() {
        while (true) {
            int user = curr % 2 == 0 ? 1 : 2;

            int y = 0;
            cout << "User " << user << " column choice?" << endl;
            cin >> y;
            if (y < 0 || y >= col) {
                cout << "Invalid move." << endl;
                continue;
            }

            int x = rowIndex[y];
            if (x < 0 || x >= row || board[x][y] != 0) {
                cout << "Invalid move." << endl;
                continue;
            }

            board[x][y] = user;
            rowIndex[y]++;

            if (hasWon(x, y, user)) {
                cout << "User " << user << " has won the game!" << endl;
                return;
            }

            curr++;
            if (curr == row * col) {
                cout << "Tie Game!" << endl;
                return;
            }
        }
    }
    
private:
    int row;
    int col;
    int curr;

    vector<int> rowIndex;
    vector<vector<int>> board;

    vector<vector<int>> dirs = {
        {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}
    };

    bool hasWon(int x, int y, int user) {
            print();

            for (int i = 0; i < dirs.size(); i++) {
                int consecutive = 1;
                
                int dx = dirs[i][0] + x;
                int dy = dirs[i][1] + y;

                while (dx >= 0 && dx < row && dy >= 0 && dy < col) {
                    if (board[dx][dy] == user) {
                        consecutive++;
                    } else {
                        break;
                    }
                    if (consecutive == 4) {
                        return true;
                    }
                    dx += dirs[i][0];
                    dy += dirs[i][1];
                }
            }

            return false;
        }
    
    void print() {
        for (int i = row - 1; i >= 0; i--) {
            for (int j = 0; j < col; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int row = 6;
    int col = 7;

    ConnectFour* obj = new ConnectFour(row, col);
    obj->play();

    return 0;
}
