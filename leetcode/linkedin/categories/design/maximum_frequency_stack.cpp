/*
    Design stack-like data structure:
    Push to stack, pop most freq element from stack

    Map val to freq, & map freq to stack of vals w/ this freq

    Time: O(1)
    Space: O(n)
*/

class FreqStack {
public:
    FreqStack() {
        maxFreq = 0;
    }
    
    void push(int val) {
        freq[val]++;
        maxFreq = max(maxFreq, freq[val]);
        
        group[freq[val]].push(val);
    }
    
    int pop() {
        int val = group[maxFreq].top();
        group[maxFreq].pop();
        
        if (group[freq[val]].empty()) {
            maxFreq--;
        }
        
        freq[val]--;
        return val;
    }
private:
    // {val -> frequency}
    unordered_map<int, int> freq;
    // {frequency -> stack of elements with this frequency}
    unordered_map<int, stack<int>> group;
    int maxFreq;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
