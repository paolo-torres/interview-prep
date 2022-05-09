/*
    Given list of working time for each employee, return list of free time
    Ex. schedule = [[[1,2],[5,6]],[[1,3]],[[4,10]]] ->
        [[3,4]], 3 employees: [-inf,1], [3,4], [10,inf], discard inf

    Add all intervals to min heap sorted by start time, check overlaps

    Time: O(n log n)
    Space: O(n)
*/

/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (int i = 0; i < schedule.size(); i++) {
            for (int j = 0; j < schedule[i].size(); j++) {
                pq.push({schedule[i][j].start, schedule[i][j].end});
            }
        }
        
        int firstStart = pq.top().first;
        int firstEnd = pq.top().second;
        pq.pop();
        
        vector<Interval> result;
        
        while (!pq.empty()) {
            int currStart = pq.top().first;
            int currEnd = pq.top().second;
            pq.pop();
            
            if (currStart > firstEnd) {
                result.push_back({firstEnd, currStart});
                firstStart = currStart;
                firstEnd = currEnd;
            } else {
                firstEnd = firstEnd > currEnd ? firstEnd : currEnd;
            }
        }
        
        return result;
    }
};
