// Timestamp buckets, mod since only care about < 300, scales

// Time: O(1) hit, O(300) getHits
// Space: O(1) hit, O(1) getHits

class HitCounter {
public:
    HitCounter() {
        hits = vector<int>(300);
        times = vector<int>(300);
    }
    
    void hit(int timestamp) {
        int index = timestamp % 300;
        if (times[index] != timestamp) {
            times[index] = timestamp;
            hits[index] = 1;
        } else {
            hits[index]++;
        }
    }
    
    int getHits(int timestamp) {
        int result = 0;
        for (int i = 0; i < 300; i++) {
            if (timestamp - times[i] < 300) {
                result += hits[i];
            }
        }
        return result;
    }
private:
    vector<int> hits;
    vector<int> times;
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
