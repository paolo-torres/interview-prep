// Map to save disjoint intervals
// Ex. m[left] = right means interval [left, right)

// Time: O(log n)
// Space: O(n)

class RangeModule {
public:
    RangeModule() {
        
    }
    
    void addRange(int left, int right) {
        // remove range at first
        removeRange(left, right);
        // add new interval [left, right) into the map
        m[left] = right;
        
        // merge prev w/ new interval in [left, right) if overlap
        auto it = m.find(left);
        if (it != m.begin() && prev(it)->second == left) {
            it--;
            it->second = right;
            m.erase(left);
        }
        if (it != prev(m.end()) && next(it)->first == right) {
            it->second = next(it)->second;
            m.erase(next(it));
        }
    }
    
    bool queryRange(int left, int right) {
        // find 1st interval i where i.left > left
        auto it = m.upper_bound(left);
        if (m.empty() || it == m.begin()) {
            return false;
        }
        it--;
        
        // if prev(i).right >= right then return true
        if (it->second >= right) {
            return true;
        }
        return false;
    }
    
    void removeRange(int left, int right) {
        if (m.empty()) {
            return;
        }
        
        // find last interval i where i.left < left
        // 1st interval that is affected by removal
        auto it = m.lower_bound(left);
        if (it != m.begin()) {
            it--;
        }
        
        vector<int> v;
        
        // check all intervals after i that intersect [left, right)
        // remove each of these intervals
        while (it != m.end() && it->first < right) {
            if (it->first < left && it->second > left) {
                int temp = it->second;
                it->second = left;
                if (temp > right) {
                    m[right] = temp;
                }
            } else if (it->first >= left) {
                v.push_back(it->first);
                if (it->second > right) {
                    m[right] = it->second;
                }
            }
            it++;
        }
        
        for (int i = 0; i < v.size(); i++) {
            m.erase(v[i]);
        }
    }
private:
    // {left interval index -> right interval index}
    map<int, int> m;
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
