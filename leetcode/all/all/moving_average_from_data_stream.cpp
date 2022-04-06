// Maintain window w/ queue

// Time: O(1)
// Space: O(n)

class MovingAverage {
public:
    MovingAverage(int size) {
        maxSize = size;
        sum = 0.0;
    }
    
    double next(int val) {
        sum += val;
        q.push(val);
        if (q.size() > maxSize) {
            sum -= q.front();
            q.pop();
        }
        return sum / q.size();
    }
private:
    queue<int> q;
    int maxSize;
    double sum;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
