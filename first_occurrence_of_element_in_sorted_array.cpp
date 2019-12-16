#include <stdio.h>

#include <iostream>
#include <vector>

using namespace std;

int findElementSorted(vector<int>& nums, int target) {
    if (nums.empty()) {
        return -1;
    }
    int low = 0;
    int high = nums.size() - 1;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] < target) {
            low = mid + 1;
        } else if (nums[mid] > target) {
            high = mid - 1;
        } else {
            if (mid == 0 || nums[mid-1] != nums[mid]) {
                return mid;
            } else {
                high = mid;
            }
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
    cout << findElementSorted(v1, x1) << endl;
    cout << findElementSorted(v2, x2) << endl;

    return 0;
}
