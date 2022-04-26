/*
    Design log system to print unique messages at most every 10 sec

    Hash map {message -> timestamp}, if exists check prev < 10 sec

    Time: O(1)
    Space: O(n) -> n = # of incoming messages
*/

class Logger {
public:
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if (m.find(message) == m.end()) {
            m[message] = timestamp;
            return true;
        }
        
        int oldTimestamp = m[message];
        if (timestamp - oldTimestamp >= 10) {
            m[message] = timestamp;
            return true;
        } else {
            return false;
        }
    }
private:
    unordered_map<string, int> m;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
