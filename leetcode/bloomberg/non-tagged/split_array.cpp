/*
    Given an unsorted array of integers, split array into 2 subarrays
    where the maximum number in the left subarray is less than the
    minimum number in the right subarray.
    Ex. [5,8,2,1,13,20] -> [5,(8),2,1] and [(13),20]

    Simple 2 pointers, for each interval, count up while within

    Time: O(n^2)
    Space: O(n)
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
    vector<vector<int>> splitArray(vector<int>& nums) {
        if (nums.size() < 2) {
            return {};
        }

        deque<int> left(nums.begin(), nums.begin() + 1);
        deque<int> right(nums.begin() + 1, nums.end());

        int leftMax = left[0];
        int rightMin = right[0];
        for (int i = 1; i < right.size(); i++) {
            rightMin = min(rightMin, right[i]);
        }

        vector<vector<int>> result;

        for (int i = 1; i < nums.size(); i++) {
            if (leftMax < rightMin) {
                vector<int> lefts(left.begin(), left.end());
                vector<int> rights(right.begin(), right.end());
                result.push_back(lefts);
                result.push_back(rights);
                return result;
            }

            left.push_back(nums[i]);
            right.pop_front();

            leftMax = max(leftMax, nums[i]);
            if (rightMin == nums[i]) {
                rightMin = getMin(right, i);
            }
        }

        return {};
    }
private:
    int getMin(deque<int>& right, int start) {
        int minVal = INT_MAX;
        for (int i = start; i < right.size(); i++) {
            minVal = min(minVal, right[i]);
        }
        return minVal;
    }
};

int main() {
    vector<int> nums = {5,8,2,1,13,20};
    Solution* obj = new Solution();
    vector<vector<int>> result = obj->splitArray(nums);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
