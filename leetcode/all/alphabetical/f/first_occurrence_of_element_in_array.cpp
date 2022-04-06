#include <stdio.h>

#include <iostream>
#include <vector>

using namespace std;

int findElement(vector<int>& nums, int value) {
    if (nums.empty()) {
        return -1;
    }
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == value) {
            return i;
        }
    }
    return -1;
}

int main()
{
    vector<int> v1 = {1, 3, 5, 5, 5, 5, 67, 123, 125};
    int x1 = 5;
    vector<int> v2 = {1, 3, 5, 5, 5, 5, 7, 123, 125};
    int x2 = 7;
    cout << findElement(v1, x1) << endl;
    cout << findElement(v2, x2) << endl;

    return 0;
}
