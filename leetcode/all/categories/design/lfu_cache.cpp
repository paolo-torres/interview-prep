/*
    Design data structure that follows constraints of an LFU cache

    Put all keys w/ same freq to a linked list so most recent one can be evicted
    Another hash map to store key's position in linked list w/ iterator
    Track least frequently used so far 

    Time: O(1)
    Space: O(capacity)
*/

class LFUCache {
public:
    LFUCache(int capacity) {
        cap = capacity;
        size = 0;
        lfu = 0;
        
    }
    
    // get node value by key, then update node frequency & position
    int get(int key) {
        if (values.find(key) == values.end()) {
            return -1;
        }
        update(key);
        return values[key].first;
    }
    
    // add new node into LFU cache, and add to doubly linked list
    void put(int key, int value) {
        if (cap == 0) {
            return;
        }
        
        if (values.find(key) != values.end()) {
            // if already has key, update node value & position in list
            values[key].first = value;
            update(key);
        } else {
            // if doesn't have key (new key being inserted)
            
            if (size == cap) {
                // if not enough space, remove LRU node in min freq list
                int evict = keys[lfu].front();
                keys[lfu].pop_front();
                values.erase(evict);
                iters.erase(evict);
            } else {
                // if enough space, increment size since we're adding 1 new
                size++;
            }
            
            // add new node to:
            
            // values map at freq 1
            values[key] = {value, 1};
            // keys map at freq 1
            keys[1].push_back(key);
            // update iterator for new node
            iters[key] = --keys[1].end();
            // new min frequency is definitely 1 (new node)
            lfu = 1;
        }
    }
private:
    int cap;
    int size;
    int lfu;
    
    // {frequency -> list of keys at this frequency}
    unordered_map<int, list<int>> keys;
    // {key -> pair (value, frequency)}
    unordered_map<int, pair<int, int>> values;
    // {key -> list iterator}
    unordered_map<int, list<int>::iterator> iters;
    
    void update(int key) {
        int freq = values[key].second;
        auto it = iters[key];
        
        // add curr node to another list w/ curr freq + 1
        // if it doesn't exist, then this list will be made anyways
        values[key].second++;
        keys[freq].erase(it);
        keys[freq + 1].push_back(key);
        iters[key] = --keys[freq + 1].end();
        
        // if curr list w/ lowest freq & curr node is only node left
        // remove entire list & increase min frequency by 1
        if (keys[lfu].empty()) {
            lfu++;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
