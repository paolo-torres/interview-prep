// Duplicates: need to store indices of all same value elements
// remove(): remove idx, swap last w/ removed, remove old + add new

// Time: O(1)
// Space: O(n)

class RandomizedCollection {
public:
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        v.push_back(val);
        if (m.find(val) != m.end()) {
            m[val].insert(v.size() - 1);
            return false;
        }
        m[val].insert(v.size() - 1);
        return true;
    }
    
    bool remove(int val) {
        auto it = m.find(val);
        if (it == m.end()) {
            return false;
        }
        
        auto free = *it->second.begin();
        it->second.erase(it->second.begin());
        
        int last = v.back();
        v[free] = last;
        m[last].insert(free);
        m[last].erase(v.size() - 1);
        v.pop_back();
        
        if (it->second.size() == 0) {
            m.erase(it);
        }
        
        return true;
    }
    
    int getRandom() {
        int index = rand() % v.size();
        return v[index];
    }
private:
    vector<int> v;
    unordered_map<int, unordered_set<int>> m;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
