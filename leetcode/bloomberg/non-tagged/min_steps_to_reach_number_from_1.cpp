/*
    It's possible to construct any integer n using a series of two
    operations: multiply by 2 or divide by 3. Find the minimum number
    of steps required to construct an integer starting from 1.
    Ex. 5  -> 1 x 2 x 2 x 2 x 2 / 3 -> 5 steps
        10 -> 1 x 2 x 2 x 2 x 2 / 3 x 2 -> 6 steps

    BFS from 1 to INF until find target, seen to ignore duplicates

    Time: O(n)
    Space: O(n)
*/

#include <stdio.h>

#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Num {
public:
    int num;
    // ex. 1x2x2x2 = 8 -> 3 operations
    int numOperations;
    string path;
    Num(int n, int o, string p) {
        num = n;
        numOperations = o;
        path = p;
    };
};

class Solution {
public:
    int getMinOperations(int target) {
        if (target <= 1) {
            return 0;
        }

        // queue for BFS, add 1 as first value
        queue<Num*> q;
        q.push(new Num(1, 0, "1"));

        // track numbers seen, add 0 to avoid num / 3 = 0
        unordered_set<int> seen;
        seen.insert(0);

        while (!q.empty()) {
            Num* curr = q.front();
            q.pop();
            seen.insert(curr->num);

            // if num from queue x2 or /3 is equal to target
            int multiply = curr->num * 2;
            int divide = curr->num / 3;
            if (multiply == target || divide == target) {
                return curr->numOperations + 1;
            }

            // if haven't seen before, add to queue
            if (seen.find(multiply) == seen.end()) {
                string operation = curr->path + "x2";
                q.push(new Num(multiply, curr->numOperations + 1, operation));
            }
            if (seen.find(divide) == seen.end()) {
                string operation = curr->path + "/3";
                q.push(new Num(divide, curr->numOperations + 1, operation));
            }
        }

        return -1;
    }
};

int main() {
    Solution* obj = new Solution();
    cout << obj->getMinOperations(5) << endl;
    cout << obj->getMinOperations(10) << endl;

    return 0;
}
