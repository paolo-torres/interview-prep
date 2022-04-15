// Exclusive time is sum of execution times for all function calls, return for each ID
// Ex. n = 2, logs = ["0:start:0","1:start:2","1:end:5","0:end:6"], output = [3,4]

// If start & there is already a prev running, add up to this point
// If end, add time diff b/w curr end + stack end
// Also if end, set start time of stack to be end of curr

// Time: O(n)
// Space: O(n)

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<pair<int, int>> s;
        vector<int> result(n, 0);
        
        for (int i = 0; i < logs.size(); i++) {
            string log = logs[i];
            stringstream ss(log);
            
            int id = 0;
            string type = "";
            int time = 0;
            
            getline(ss, log, ':');
            id = stoi(log);
            getline(ss, log, ':');
            type = log;
            getline(ss, log, ':');
            time = stoi(log);
            
            if (type == "start") {
                if (!s.empty()) {
                    int prevId = s.top().first;
                    int prevTime = s.top().second;
                    result[prevId] += time - prevTime;
                }
                s.push({id, time});
            } else {
                int currId = s.top().first;
                int currTime = s.top().second;
                s.pop();
                result[currId] += time - currTime + 1;
                if (!s.empty()) {
                    s.top().second = time + 1;
                }
            }
        }
        
        return result;
    }
};
