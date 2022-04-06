#include <stdio.h>

#include <iostream>
#include <vector>

using namespace std;

int maximumDifference(vector<int>& nums) {
    if (nums.empty()) {
        return -1;
    }
    int minValue = nums[0];
    int maxDiff = -1;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < minValue) {
            minValue = nums[i];
        }
        if (nums[i] - minValue > maxDiff) {
            maxDiff = nums[i] - minValue;
        }
    }
    return maxDiff;
}

int main()
{
    vector<int> v1 = {2, 3, 10, 6, 4, 8, 1};
    vector<int> v2 = {7, 9, 5, 6, 3, 2};
    vector<int> v3 = {5, 10, 7, 6, 4, 3, 1};
    cout << "v1: " << maximumDifference(v1) << endl;
    cout << "v2: " << maximumDifference(v2) << endl;
    cout << "v3: " << maximumDifference(v3) << endl;

    return 0;
}
