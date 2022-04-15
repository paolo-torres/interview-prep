// Design data structure to store strings' count
// With ability to return the strings w/ min & max counts

// For each value, have bucket w/ all keys that map to this value
// Buckets are in a list sorted by value, allows O(1) insert, remove, & iteration
// A bucket stores its keys in a hash set for O(1) insert, remove & lookup
// Hash map to lookup which bucket a given key is in

// Time: O(1)
// Space: O(n)

class AllOne {
public:
    AllOne() {
        
    }
    
    void inc(string key) {
        // if key doesn't exist, insert w/ value 0
        if (bucketOfKey.find(key) == bucketOfKey.end()) {
            bucketOfKey[key] = buckets.insert(buckets.begin(), {0, {key}});
        }
        
        // insert key in next bucket & update lookup
        auto next = bucketOfKey[key];
        auto bucket = next;
        next++;
        if (next == buckets.end() || next->val > bucket->val + 1) {
            next = buckets.insert(next, {bucket->val + 1, {}});
        }
        next->keys.insert(key);
        bucketOfKey[key] = next;
        
        // remove key from old bucket
        bucket->keys.erase(key);
        if (bucket->keys.empty()) {
            buckets.erase(bucket);
        }
    }
    
    void dec(string key) {
        // if key doesn't exist, do nothing
        if (bucketOfKey.find(key) == bucketOfKey.end()) {
            return;
        }
        
        // maybe insert key in prev bucket & update lookup
        auto prev = bucketOfKey[key];
        auto bucket = prev;
        prev--;
        bucketOfKey.erase(key);
        if (bucket->val > 1) {
            if (bucket == buckets.begin() || prev->val < bucket->val - 1) {
                prev = buckets.insert(bucket, {bucket->val - 1, {}});
            }
            prev->keys.insert(key);
            bucketOfKey[key] = prev;
        }
        
        // remove key from old bucket
        bucket->keys.erase(key);
        if (bucket->keys.empty()) {
            buckets.erase(bucket);
        }
    }
    
    string getMaxKey() {
        if (buckets.empty()) {
            return "";
        }
        return *(buckets.rbegin()->keys.begin());
    }
    
    string getMinKey() {
        if (buckets.empty()) {
            return "";
        }
        return *(buckets.begin()->keys.begin());
    }
private:
    struct Bucket {
        int val;
        unordered_set<string> keys;
    };
    list<Bucket> buckets;
    unordered_map<string, list<Bucket>::iterator> bucketOfKey;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
