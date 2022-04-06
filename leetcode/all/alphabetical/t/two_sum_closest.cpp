#include <stdio.h>

#include <iostream>

#include <algorithm>
#include <vector>

using namespace std;

vector<int> twoSumClosest(vector<int>& nums, int target) {
    vector<int> result = {-1, -1};
    if (nums.size() < 2) {
        return result;
    }
    sort(nums.begin(), nums.end());
    int i = 0;
    int j = nums.size() - 1;
    int temp = 0;
    int closest = 0;
    while (i < j) {
        if (nums[i] + nums[j] == target) {
            result[0] = nums[i];
            result[1] = nums[j];
            break;
        } else if (nums[i] + nums[j] < target) {
            if (nums[i] + nums[j] > temp) {
                temp = nums[i] + nums[j];
                result[0] = nums[i];
                result[1] = nums[j];
            }
            i++;
        } else {
            j--;
        }
    }
    return result;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    int target = 10;
    vector<int> test = twoSumClosest(nums, target);
    cout << test[0] << " " << test[1] << endl;

    return 0;
}
