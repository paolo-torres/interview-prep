// Hash map: {tweet -> times}, get # of tweets within time chunk

// Time: O(1) recordTweet, O(n) getTweetCountsPerFrequency
// Space: O(1) recordTweet, O(n) getTweetCountsPerFrequency

class TweetCounts {
public:
    TweetCounts() {
        f = {{"minute", 60}, {"hour", 3600}, {"day", 86400}};
    }
    
    void recordTweet(string tweetName, int time) {
        m[tweetName].push_back(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        vector<int> result;
        
        int timeChunks = (endTime - startTime) / f[freq];
        for (int i = 0; i <= timeChunks; i++) {
            result.push_back(0);
        }
        
        vector<int> times = m[tweetName];
        for (int i = 0; i < times.size(); i++) {
            if (startTime <= times[i] && times[i] <= endTime) {
                int timeChunk = (times[i] - startTime) / f[freq];
                result[timeChunk]++;
            }
        }
        
        return result;
    }
private:
    unordered_map<string, vector<int>> m;
    unordered_map<string, int> f;
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
