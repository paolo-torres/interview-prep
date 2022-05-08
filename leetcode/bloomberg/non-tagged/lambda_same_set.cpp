/*
    Given a list of elements and a lambda function. The lambda function
    takes 2 elements and returns true if they belong to the same set.
    Return a list of lists, where each sublist are elements in the
    same set.
    Ex. nums = [12,11,1,3,9,6,8] and lambdaFunc(a, b): a % 2 == b % 2
    [[11,1,3,9],[12,6,8]] -> set of odd numbers & set of even numbers

    Hash map of sets, if lambda function returns true add to set

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
    vector<vector<int>> sameSet(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (m.find(nums[i]) != m.end()) {
                continue;
            }
            bool foundSet = false;
            for (auto it = m.begin(); it != m.end(); it++) {
                if (lambdaFunc(it->first, nums[i])) {
                    it->second.push_back(nums[i]);
                    foundSet = true;
                    break;
                }
            }
            if (!foundSet) {
                m.insert({nums[i], {}});
            }
        }

        vector<vector<int>> result;
        for (auto it = m.begin(); it != m.end(); it++) {
            vector<int> curr = {it->first};
            curr.insert(curr.end(), it->second.begin(), it->second.end());
            result.push_back(curr);
        }
        return result;
    }
private:
    unordered_map<int, vector<int>> m;

    bool lambdaFunc(int a, int b) {
        return a % 2 == b % 2;
    }
};

int main() {
    vector<int> nums = {12, 11, 1, 3, 9, 6, 8};
    Solution* obj = new Solution();
    vector<vector<int>> result = obj->sameSet(nums);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
