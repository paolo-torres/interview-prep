/*
    Given some numbers and an interval list, how many numbers occur
    between each interval?
    Ex. nums = [3,5,7,8,10], intervals = [1,6,15]
    [2,3] i.e., [1,6] -> [3,5] and [6,15] -> [7,8,10] (2 & 3 nums)

    Simple 2 pointers, for each interval, count up while within

    Time: O(m + n)
    Space: O(1)
*/

#include <stdio.h>

#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> numbersInIntervals(vector<int>& nums, vector<int>& intervals) {
        int n = nums.size();
        int i = 0;

        int start = 0;
        int end = 1;

        vector<int> result;

        while (i < n && end < intervals.size()) {
            int count = 0;

            while (i < n && nums[i] < intervals[start]) {
                i++;
            }
            while (i < n && nums[i] < intervals[end]) {
                count++;
                i++;
            }

            start++;
            end++;

            result.push_back(count);
        }

        return result;
    }
};

int main() {
    vector<int> nums = {3,5,7,8,10};
    vector<int> intervals = {1,6,15};
    Solution* obj = new Solution();

    vector<int> result = obj->numbersInIntervals(nums, intervals);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }

    return 0;
}
