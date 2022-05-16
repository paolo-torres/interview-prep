/*
    Given a 5x5 grid, create a bingo card with the following:
        - middle square in middle column must have free space (-1)
        - must generate random numbers per column as follows:
            - col1: 1-15
            - col2: 16-30
            - col3: 31-45
            - col4: 46-60
            - col5: 61-75
        - ex:
            2   17  37  49  62
            5   22  41  52  70
            6   23  -1  59  68
            9   18  42  60  69
            8   29  40  55  63

    Time: O(n)
    Space: O(n)
*/

#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <queue>
#include <map>
#include <stack>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> bingoCard() {
        vector<int> randNums(RAND_RANGE);
        vector<vector<int>> result(BINGO_SIZE,
            vector<int>(BINGO_SIZE));
        
        for (int i = 0; i < RAND_RANGE; i++) {
            randNums[i] = i + 1;
        }
        for (int i = 0; i < BINGO_SIZE; i++) {
            shuffle(randNums);
            for (int j = 0; j < BINGO_SIZE; j++) {
                result[j][i] = randNums[j] + (i * RAND_RANGE);
            }
        }

        result[2][2] = -1;
        return result;
    }
private:
    const int BINGO_SIZE = 5;
    const int RAND_RANGE = 15;

    void shuffle(vector<int>& nums) {
        srand(time(NULL));
        for (int i = 0; i < nums.size(); i++) {
            int index = i + rand() % (nums.size() - i);
            swap(nums[i], nums[index]);
        }
    }
};

int main() {
    Solution* obj = new Solution();
    vector<vector<int>> result = obj->bingoCard();
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
