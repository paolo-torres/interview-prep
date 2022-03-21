#include <stdio.h>

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int mostFrequentElement(vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }
    unordered_map<int, int> m;
    int value = 0;
    int freq = 0;
    for (int i = 0; i < nums.size(); i++) {
        auto it = m.find(nums[i]);
        if (it != m.end()) {
            it->second++;
            if (it->second > freq) {
                value = it->first;
                freq = it->second;
            }
        } else {
            m.insert({nums[i], 1});
            if (m.size() == 1) {
                auto it = m.find(nums[i]);
                value = it->first;
                freq = it->second;
            }
        }
    }
    int result = 0;
    while (freq > 0) {
        result += value;
        freq--;
    }
    return result;
}

int main()
{
    vector<int> nums1 = {1, 3, 2, 1, 4, 1};
    vector<int> nums2 = {10, 20, 10, 20, 30, 20, 20};
    cout << mostFrequentElement(nums1) << endl;
    cout << mostFrequentElement(nums2) << endl;

    return 0;
}
