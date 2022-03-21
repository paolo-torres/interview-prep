// Time: O(n log n)
// Space: O(n)

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });
        
        priority_queue<int> pq;
        
        int time = 0;
        int result = 0;
        
        for (int i = 0; i < courses.size(); i++) {
            int duration = courses[i][0];
            int lastDay = courses[i][1];
            
            pq.push(duration);
            time += duration;
            result++;
            
            if (time > lastDay) {
                time -= pq.top();
                pq.pop();
                result--;
            }
        }
        
        return result;
    }
};
