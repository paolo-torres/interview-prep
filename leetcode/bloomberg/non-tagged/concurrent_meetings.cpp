/*
    Given a list of meetings for a given day in a conference center,
    return a list of time slots during which the most number of
    concurrent meetings are held. Each meeting has a start time and
    end time, and occupies a single room in a conference center.
    Ex.
        Input: [[100,300],[145,215],[200,230],[215,300],[215,400],
                [500,600],[600,700]]
        Output: [4,215,230]

    Same as Meeting Rooms II, except track maxStart/End (bigger size)

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
    vector<int> concurrentMeetings(vector<vector<int>>& intervals) {
        // sort intervals by start time
        sort(intervals.begin(), intervals.end());
        
        // min heap to track min end time of merged intervals
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(intervals[0][1]);

        int maxLength = 0;
        int maxStart = 0;
        int maxEnd = 0;
        
        for (int i = 1; i < intervals.size(); i++) {
            // compare curr start w/ earliest end time, if no overlap then pop
            if (intervals[i][0] >= pq.top()) {
                pq.pop();
            }
            // add new room (will replace/be same size if above was true)
            pq.push(intervals[i][1]);

            if (pq.size() > maxLength) {
                maxLength = pq.size();
                maxStart = intervals[i][0];
                maxEnd = pq.top();
            }
        }
        
        return {maxLength, maxStart, maxEnd};
    }
};

int main() {
    vector<vector<int>> intervals = {
        {100, 300}, {145, 215}, {200, 230}, {215, 300}, {215, 400},
        {500, 600}, {600, 700}
    };
    Solution* obj = new Solution();
    vector<int> result = obj->concurrentMeetings(intervals);

    cout << result[0] << " " << result[1] << " " << result[2] << endl;

    return 0;
}
