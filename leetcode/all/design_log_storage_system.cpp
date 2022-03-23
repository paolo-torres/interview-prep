// Hash map: {timestamp -> id}, lexicographical compare within range

// Time: O(1) put, O(n) retrieve
// Space: O(1) put, O(n) retrieve

class LogSystem {
public:
    LogSystem() {
        precision = {
            {"Year", 4},
            {"Month", 7},
            {"Day", 10},
            {"Hour", 13},
            {"Minute", 16},
            {"Second", 19}
        };
    }
    
    void put(int id, string timestamp) {
        logs[timestamp] = id;
    }
    
    vector<int> retrieve(string start, string end, string granularity) {
        vector<int> result;
        
        for (auto it = logs.begin(); it != logs.end(); it++) {
            int len = precision[granularity];
            
            start = start.substr(0, len);
            end = end.substr(0, len);
            
            string curr = it->first.substr(0, len);
            if (start <= curr && curr <= end) {
                result.push_back(it->second);
            }
        }
        
        return result;
    }
private:
    unordered_map<string, int> logs;
    unordered_map<string, int> precision;
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem* obj = new LogSystem();
 * obj->put(id,timestamp);
 * vector<int> param_2 = obj->retrieve(start,end,granularity);
 */
