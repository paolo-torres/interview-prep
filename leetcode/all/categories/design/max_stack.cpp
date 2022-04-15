// Design max stack data structure that supports stack operations
// Also supports finding the stack's maximum element

// Initial approach: 2 stacks, for peek remember largest value seen so far
// Ex. [2,1,5,3,9] -> [2,2,5,5,9], for pop can pop until max, then push back

// Optimized: DLL + map, DLL as "stack", map {values -> list of nodes}
// O(1) removal from DLL, O(log n) insert, removal, lookup in map

// Time: O(log n) push, O(log n) pop & popMax, O(1) top & peekMax
// Space: O(n)

class MaxStack {
public:
    MaxStack() {
        
    }
    
    void push(int x) {
        dll.push_front(x);
        m[x].push_back(dll.begin());
    }
    
    int pop() {
        int x = dll.front();
        m[x].pop_back();
        if (m[x].empty()) {
            m.erase(x);
        }
        dll.pop_front();
        return x;
    }
    
    int top() {
        return dll.front();
    }
    
    int peekMax() {
        return m.begin()->first;
    }
    
    int popMax() {
        int x = m.begin()->first;
        auto it = (m.begin()->second).back();
        dll.erase(it);
        m[x].pop_back();
        if (m[x].empty()) {
            m.erase(x);
        }
        return x;
    }
private:
    // doubly linked list for O(1) insert/delete
    list<int> dll;
    // sorted map, largest key at begin(), O(1) find max, O(log n) insert/delete
    map<int, vector<list<int>::iterator>, greater<int>> m;
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */

// class MaxStack {
// public:
//     MaxStack() {
        
//     }
    
//     void push(int x) {
//         s1.push(x);
//         if (s2.empty() || s2.top() <= x) {
//             s2.push(x);
//         }
//     }
    
//     int pop() {
//         int x = s1.top();
//         s1.pop();
//         if (x == peekMax()) {
//             s2.pop();
//         }
//         return x;
//     }
    
//     int top() {
//         return s1.top();
//     }
    
//     int peekMax() {
//         return s2.top();
//     }
    
//     int popMax() {
//         int x = peekMax();
//         stack<int> temp;
//         while (top() != x) {
//             temp.push(pop());
//         }
//         pop();
//         while (!temp.empty()) {
//             push(temp.top());
//             temp.pop();
//         }
//         return x;
//     }
// private:
//     stack<int> s1;
//     stack<int> s2;
// };
