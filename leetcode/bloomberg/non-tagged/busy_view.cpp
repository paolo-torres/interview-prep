/*
    Given list of events of a given day in a calendar, write an
    algorithm to return a list of busy view time slots. Busy view is
    created by consolidating adjacent & overlapping event time slots.
    
    Exactly the same as Merge Intervals, merge overlapping intervals.

    Time: O(n log n)
    Space: O(n)
*/

#include <stdio.h>

#include <iostream>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> busyView(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 1) {
            return intervals;
        }
        
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
           return a[0] < b[0]; 
        });
        
        vector<vector<int>> result;
        
        int i = 0;
        while (i < n - 1) {
            if (intervals[i][1] >= intervals[i+1][0]) {
                intervals[i+1][0] = intervals[i][0];
                intervals[i+1][1] = max(intervals[i][1], intervals[i+1][1]);
            } else {
                result.push_back(intervals[i]);
            }
            i++;
        }
        result.push_back(intervals[i]);
        
        return result;
    }
};

int main() {
    vector<vector<int>> intervals = {
        {100, 300},
        {115, 145},
        {145, 215},
        {200, 400},
        {215, 230},
        {215, 415},
        {600, 700},
        {500, 600}
    };
    Solution* obj = new Solution();

    vector<vector<int>> result = obj->busyView(intervals);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i][0] << "," << result[i][1] << endl;
    }

    return 0;
}
