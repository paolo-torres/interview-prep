/*
    Implement a SnapshotArray data structure

    Whole array could get large (multiple snap calls)
    Instead of history of whole array, history of each index
    Use binary search to find snapId in history

    Time: O(log s) -> s = # of times set is called
    Space: O(s)
*/

class SnapshotArray {
public:
    SnapshotArray(int length) {
        for (int i = 0; i < length; i++) {
            map<int, int> m;
            m[0] = 0;
            snaps[i] = m;
        }
        snapId = 0;
    }
    
    void set(int index, int val) {
        snaps[index][snapId] = val;
    }
    
    int snap() {
        snapId++;
        return snapId - 1;
    }
    
    int get(int index, int snap_id) {
        // gets iterator pos at snap_id
        auto it = snaps[index].upper_bound(snap_id);
        it--;
        // returns val at snap_id
        return it->second;
    }
private:
    // {index -> {snapId -> val}}
    unordered_map<int, map<int, int>> snaps;
    int snapId;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
