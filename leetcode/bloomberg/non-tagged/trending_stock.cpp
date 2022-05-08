/*
    Implement TrendingStock(), a class which simulates and outputs the
    most frequently traded stock.
    2 functions:
        1) processStock(string stock): processes stock into the system.
        2) getTrendingStock(): removes & returns most frequently
            traded stock in the system, if there's a tie, stock most
            recently traded is removed and returned.

    Same as LFU cache except most frequently used (MFU cache)
    Put all keys w/ same freq to a linked list so most recent one can be evicted
    Another hash map to store key's position in linked list w/ iterator
    Track most frequently used so far

    Time: O(1)
    Space: O(n)
*/

#include <iostream>
#include <list>
#include <string>
#include <unordered_map>

using namespace std;

class TrendingStock {
public:
    // freq list
    list<int> freqlist;

    TrendingStock() {
        max_freq = 0;
    }

    void processStock(const string& stock) {
        if (key_freq.count(stock) == 0) {
            key_freq[stock] = 1;
            freq_map[1].push_back(stock);
            key_it[stock] = --freq_map[1].end();

            if (freqlist.empty()) {
                freqlist.push_back(1);
                maxfreq_map[1] = prev(freqlist.end());
            }

            return;
        }

        int freq = key_freq[stock];
        auto it = key_it[stock];
        freq_map[freq].erase(it);
        
        if (freq_map[freq].size() == 0) {
            auto it = maxfreq_map[freq];
            freqlist.erase(it);
        }
        
        freq_map[freq + 1].push_back(stock);
        key_it[stock] = --freq_map[freq + 1].end();
        key_freq[stock] = freq + 1;
        max_freq = freqlist.back();

        if (freq + 1 > max_freq) {
            freqlist.push_back(freq + 1);
            maxfreq_map[freq + 1] = prev(freqlist.end());
        }
    }

   string getTrendingStock() {
        max_freq = freqlist.back();
        string res = freq_map[max_freq].back();
        freq_map[max_freq].pop_back();

        key_freq.erase(res);
        key_it.erase(res);

        if (freq_map[max_freq].size() == 0) {
            auto it = maxfreq_map[max_freq];
            freqlist.erase(it);
        }
        return res;
    }
private:
    // stock to freq map
    unordered_map<string, int> key_freq;
    // stock to iterator map
    unordered_map<string, list<string>::iterator> key_it;
    // freq to list of stocks map
    unordered_map<int, list<string>> freq_map;
    // freq to list iterator map
    unordered_map<int, list<int>::iterator> maxfreq_map;
    int max_freq;
};

int main() {
    TrendingStock *obj = new TrendingStock();

    obj->processStock("TSLA");
    obj->processStock("TSLA");
    obj->processStock("TSLA");
    obj->processStock("TSLA");
    obj->processStock("TSLA");
    cout << obj->freqlist.back() << " ";
    cout << obj->getTrendingStock() << endl;

    obj->processStock("AAPL");
    obj->processStock("AAPL");
    obj->processStock("AAPL");
    cout <<  obj->freqlist.back() << " ";
    cout << obj->getTrendingStock() <<  endl;

    return 0;
}
