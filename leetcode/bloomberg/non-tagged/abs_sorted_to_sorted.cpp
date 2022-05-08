/*
	Given an array sorted by its absolute values, return sorted
    array by its actual values.
    Ex. [0,-1,2,-4,5,6,-10,-13,-22] -> [-22,-13,-10,-4,-1,0,2,5,6]

    Deque, append to left if < 0, append to right if >= 0

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

class Solution {
public:
    vector<int> absSortedToSorted(vector<int>& nums) {
        deque<int> dq;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= 0) {
                dq.push_back(nums[i]);
            } else {
                dq.push_front(nums[i]);
            }
        }
        return vector<int>(dq.begin(), dq.end());
    }
};

int main() {
    vector<int> nums = {0, -1, 2, -4, 5, 6, -10, -13, -22};
    Solution* obj = new Solution();
    vector<int> result = obj->absSortedToSorted(nums);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
