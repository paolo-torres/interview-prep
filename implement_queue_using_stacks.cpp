class MyQueue {
private:
    stack<int> mainStack;
    stack<int> tempStack;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        mainStack.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int length = mainStack.size();
        for (int i = 0; i < length; i++) {
            tempStack.push(mainStack.top());
            mainStack.pop();
        }
        int result = tempStack.top();
        tempStack.pop();
        length = tempStack.size();
        for (int i = 0; i < length; i++) {
            mainStack.push(tempStack.top());
            tempStack.pop();
        }
        return result;
    }
    
    /** Get the front element. */
    int peek() {
        int length = mainStack.size();
        for (int i = 0; i < length; i++) {
            tempStack.push(mainStack.top());
            mainStack.pop();
        }
        int result = tempStack.top();
        for (int i = 0; i < length; i++) {
            mainStack.push(tempStack.top());
            tempStack.pop();
        }
        return result;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        if (mainStack.empty()) {
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
