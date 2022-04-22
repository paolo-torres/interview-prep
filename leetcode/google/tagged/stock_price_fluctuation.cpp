/*
    StockPrice class: update price, find latest price, find max, find min

    Hash map {timestamp -> price}, multiset {prices}, update price if needed

    Time: O(log n)
    Space: O(n)
*/

class StockPrice {
public:
    StockPrice() {
        lastTimestamp = 0;
        lastPrice = 0;
    }
    
    void update(int timestamp, int price) {
        // get price at this timestamp
        auto it = m.find(timestamp);
        // if there's already one, remove old one
        if (it != m.end()) {
            prices.erase(prices.find(it->second));
        }
        // insert new one & update hash map
        prices.insert(price);
        m[timestamp] = price;
        if (timestamp >= lastTimestamp) {
            lastTimestamp = timestamp;
            lastPrice = price;
        }
    }
    
    int current() {
        return lastPrice;
    }
    
    int maximum() {
        auto it = prices.end();
        it--;
        return *it;
    }
    
    int minimum() {
        auto it = prices.begin();
        return *it;
    }
private:
    // {timestamp -> price}
    unordered_map<int, int> m;
    // ordered set of prices (allows duplicates)
    multiset<int> prices;
    
    int lastTimestamp;
    int lastPrice;
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
