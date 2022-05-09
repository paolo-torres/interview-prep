/*
    Given a list of operation hours for each stock exchange, validate
    if the customer can send a trading order during the input hour.
    Ex.
    Operation Hours
    09:00 - 16:00 Royal Bank of Scotland
    11:00 - 17:00 Morgan Stanley
    Test 1: 10:00 - 17:00 -> SUCCESS
    Test 2: 15:00 - 21:00 -> FAILURE

    Exactly the same as Merge Intervals, merge & check order intervals

    Time: O(n log n)
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
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
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
    vector<vector<int>> intervals = {{900, 1600}, {1100, 1700}};
    Solution* obj = new Solution();
    vector<vector<int>> operationHours = obj->merge(intervals);

    vector<int> test1 = {1000, 1700};
    bool isSuccess = false;

    for (int i = 0; i < operationHours.size(); i++) {
        if (operationHours[i][0] <= test1[0]
            && operationHours[i][1] <= test1[1]) {
            cout << "SUCCESS" << endl;
            isSuccess = true;
            break;
        }
    }
    if (!isSuccess) {
        cout << "FAILURE";
    }

    vector<int> test2 = {1500, 2100};
    isSuccess = false;

    for (int i = 0; i < operationHours.size(); i++) {
        if (operationHours[i][0] <= test2[0]
            && test2[1] <= operationHours[i][1]) {
            cout << "SUCCESS" << endl;
            isSuccess = true;
            break;
        }
    }
    if (!isSuccess) {
        cout << "FAILURE" << endl;
    }

    return 0;
}
