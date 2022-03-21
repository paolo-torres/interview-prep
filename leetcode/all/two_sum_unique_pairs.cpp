#include <stdio.h>

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int twoSumUnique(vector<int>& nums, int target) {
    unordered_map<int, int> pairs;
    int result = 0;
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        auto it = pairs.find(complement);
        if (it != pairs.end() && it->second == 0) {
            it->second++;
            result++;
        } else {
            pairs.insert({nums[i], 0});
        }
    }
    return result;
}

int main()
{
    vector<int> nums1 = {1, 1, 2, 45, 46, 46};
    vector<int> nums2 = {1, 1};
    vector<int> nums3 = {1, 5, 1, 5};
    int target1 = 47;
    int target2 = 2;
    int target3 = 6;
    int ans1 = twoSumUnique(nums1, target1);
    int ans2 = twoSumUnique(nums2, target2);
    int ans3 = twoSumUnique(nums3, target3);
    cout << ans1 << " " << ans2 << " " << ans3 << endl;

    return 0;
}
