#include <stdio.h>

#include <iostream>
#include <vector>

using namespace std;

int searchInfinite(vector<int>& nums, int target) {
    int low = 0;
    int high = 1;
    int mid = low + (high - low) / 2;
    while (nums[mid] != target) {
        if (nums[high] < target) {
            low = high + 1;
            high *= 2;
            continue;
        }
        mid = low + (high - low) / 2;
        if (nums[mid] < target) {
            low = mid + 1;
        } else if (nums[mid] > target) {
            high = mid - 1;
        } else {
            break;
        }
    }
    return mid;
}

int main()
{
    vector<int> v1 = {3, 5, 7, 9, 10, 90, 100, 130, 140, 160, 170};
    vector<int> v2;
    for (int i = 0; i < 1000000; i++) {
        v2.push_back(i);
    } 
    int target1 = 10;
    int target2 = 500000;
    cout << "v1: " << searchInfinite(v1, target1) << endl;
    cout << "v2: " << searchInfinite(v2, target2) << endl;

    return 0;
}
