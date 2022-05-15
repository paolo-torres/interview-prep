// Time: O(1)
// Space: O(n)

class FreqStack {
public:
    FreqStack() {
        maxFreq = 0;
    }
    
    void push(int val) {
        freq[val]++;
        m[freq[val]].push(val);
        maxFreq = max(maxFreq, freq[val]);
    }
    
    int pop() {
        int val = m[maxFreq].top();
        m[maxFreq].pop();
        
        if (m[freq[val]].empty()) {
            maxFreq--;
        }
        
        freq[val]--;
        return val;
    }
private:
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> m;
    int maxFreq;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
