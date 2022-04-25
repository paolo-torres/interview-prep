/*
    Given tasks where tasks[i] = [iEnqueueTime, iProcessingTime]:
    Can process at most 1 task at a time w/ the following:
        If CPU idle & no available tasks to process, CPU remains idle
        If CPU idle & tasks available, chooses shortest processing time
        Once a task is started, CPU will process entire task w/o stopping
    Return the order in which the CPU will process the tasks
    Ex. tasks = [[1,2],[2,4],[3,2],[4,1]] -> [0,2,3,1]

    Min heap to sort avail tasks by processing time, sort tasks by enqueue time
    When time >= enqueue time, keep pushing to heap, then pop and handle task

    Time: O(n log n)
    Space: O(n)
*/

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        
        for (int i = 0; i < n; i++) {
            tasks[i].push_back(i);
        }
        // to take tasks of earliest enqueue time first
        sort(tasks.begin(), tasks.end());
        
        // min heap of tasks, sorted by processing time, then by index
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<int> result;
        
        int i = 0;
        long time = 0;
        
        while (i < n || !pq.empty()) {
            // if heap empty, try update curr time w/ enqueue time of next task
            if (pq.empty()) {
                time = max(time, (long)tasks[i][0]);
            }
            
            // push all tasks where enqueue time <= current time
            while (i < n && time >= tasks[i][0]) {
                pq.push({tasks[i][1], tasks[i][2]});
                i++;
            }
            
            pair<int, int> curr = pq.top();
            int processingTime = curr.first;
            int index = curr.second;
            pq.pop();
            
            // handle task and increase current time by the processing time
            time += processingTime;
            result.push_back(index);
        }
        
        return result;
    }
};
