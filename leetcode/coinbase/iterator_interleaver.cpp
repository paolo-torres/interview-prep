/*
    Given 2D array of nums, output results in an interleaving fashion.
    Ex. [[1,2,3],[4,5],[6],[],[7,8,9]] -> [1,4,6,7,2,5,8,3,9]

    Create a series of iterators:
        - Range: Takes start, end & increment, & outputs numbers between.
            - RangeIterator(0, 10, 2) -> output: [0,2,4,6,8,10]
        - Interleaving.
        - Cycle: Takes in another iterator implemented above and keeps
            repeating the data once end is reached.

    Queue, first push all (i, 0) indices, then push j increments

    Time: O(n)
    Space: O(n)
*/

#include <stdio.h>

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Interleaver {
public:
    Interleaver(vector<vector<int>> arr, bool cycle) {
        nums = arr;
        shouldCycle = cycle;
        reset();
    }

    bool hasNext() {
        return shouldCycle || !q.empty();
    }

    int next() {
        if (q.empty()) {
            if (shouldCycle) {
                reset();
            } else {
                return 0;
            }
        }

        vector<int> curr = q.front();
        q.pop();
        int i = curr[0];
        int j = curr[1];

        if (j < nums[i].size() - 1) {
            q.push({i, j + 1});
        }

        return nums[i][j];
    }

    void reset() {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i].size() > 0) {
                q.push({i, 0});
            }
        }
    }
private:
    vector<vector<int>> nums;
    bool shouldCycle;
    queue<vector<int>> q;
};

int main() {
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5}, {6}, {}, {7, 8, 9}};
    Interleaver* obj = new Interleaver(arr, true);
    for (int i = 0; i < 12; i++) {
        cout << i << " next: " << obj->next() << endl;
    }

    return 0;
}
