// Greedy, remove longest length courses, minimizes removals, max # of courses

// Time: O(n log n)
// Space: O(n)

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        // greedy: sort courses by earliest finish time
        sort(courses.begin(), courses.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });
        
        priority_queue<int> pq;
        int time = 0;
        
        for (int i = 0; i < courses.size(); i++) {
            int duration = courses[i][0];
            int lastDay = courses[i][1];
            
            // add current course to max heap
            pq.push(duration);
            time += duration;
            
            // if time exceeds, drop course which takes the longest
            if (time > lastDay) {
                time -= pq.top();
                pq.pop();
            }
        }
        
        return pq.size();
    }
};
