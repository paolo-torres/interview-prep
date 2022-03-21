class LRUCache {
private:
    unordered_map<int, int> m;
    unordered_map<int, int> visited;
    deque<int> dq;
    int count = 0;
    int size = 0;
public:
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if (m.find(key) == m.end() || m[key] == -1) {
            return -1;
        }
        dq.push_back(key);
        visited[key]++;
        return m[key];
    }
    
    void put(int key, int value) {
        if (m.find(key) == m.end() || m[key] == -1) {
            count++;
        } else {
            visited[key]++;
        }
        if (count > size) {
            while (visited[dq.front()] != 0) {
                visited[dq.front()]--;
                dq.pop_front();
            }
            m[dq.front()] = -1;
            dq.pop_front();
            count--;
        }
        dq.push_back(key);
        m[key] = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
