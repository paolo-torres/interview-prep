#include <stdio.h>

#include <iostream>
#include <iterator>
#include <map>
#include <vector>

using namespace std;

vector<int> pairSum(vector<int>& nums, int target) {
    map<int, int> m;
    vector<int> result(2, 0);
    for (int i = nums.size() - 1; i >= 0; i--) {
        int complement = target - 30 - nums[i];
        auto it = m.find(complement);
        if (it != m.end()) {
            result[0] = i;
            result[1] = it->second;
            break;
        } else {
            m.insert({nums[i], i});
        }
    }
    return result;
}

int main()
{
    vector<int> nums1 = {1, 10, 25, 35, 60};
    vector<int> nums2 = {20, 50, 40, 25, 30, 10};
    int target = 90;
    vector<int> test1 = pairSum(nums1, target);
    vector<int> test2 = pairSum(nums2, target);
    for (int i = 0; i < test1.size(); i++) {
        cout << test1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < test2.size(); i++) {
        cout << test2[i] << " ";
    }

    return 0;
}
