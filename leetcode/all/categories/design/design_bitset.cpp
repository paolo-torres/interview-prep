// Maintain flipped version of s, keep count of ones in s

// Time: O(1)
// Space: O(size)

class Bitset {
public:
    Bitset(int size) {
        s = string(size, '0');
        flipped = string(size, '1');
        sz = size;
        ones = 0;
    }
    
    void fix(int idx) {
        if (s[idx] == '0') {
            ones++;
        }
        s[idx] = '1';
        flipped[idx] = '0';
    }
    
    void unfix(int idx) {
        if (s[idx] == '1') {
            ones--;
        }
        s[idx] = '0';
        flipped[idx] = '1';
    }
    
    void flip() {
        swap(s, flipped);
        ones = sz - ones;
    }
    
    bool all() {
        return ones == sz;
    }
    
    bool one() {
        return ones;
    }
    
    int count() {
        return ones;
    }
    
    string toString() {
        return s;
    }
private:
    string s;
    string flipped;
    int sz;
    int ones;
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */
