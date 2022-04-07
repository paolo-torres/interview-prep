class MyQueue {
private:
    stack<int> main;
    stack<int> temp;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        while (!main.empty()) {
            temp.push(main.top());
            main.pop();
        }
        temp.push(x);
        while (!temp.empty()) {
            main.push(temp.top());
            temp.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int result = main.top();
        main.pop();
        return result;
    }
    
    /** Get the front element. */
    int peek() {
        return main.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        if (main.empty()) {
            return true;
        } else {
            return false;
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
