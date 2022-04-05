// 2 stacks -> optimize w/ simple vector

// Time: O(1)
// Space: O(n)

class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        index = 0;
        history.push_back(homepage);
    }
    
    void visit(string url) {
        index++;
        // resize to trim forward history
        history.resize(index);
        history.push_back(url);
    }
    
    string back(int steps) {
        // clamp to 0 if at first URL
        index = max(0, index - steps);
        return history[index];
    }
    
    string forward(int steps) {
        // clamp to history size if at last URL
        index = min(index + steps, (int) history.size() - 1);
        return history[index];
    }
private:
    int index;
    vector<string> history;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
