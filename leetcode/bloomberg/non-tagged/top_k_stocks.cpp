/*
	Given an array sorted by its absolute values, return sorted
    array by its actual values.
    Ex. [0,-1,2,-4,5,6,-10,-13,-22] -> [-22,-13,-10,-4,-1,0,2,5,6]

    Same as Design a Leaderboard, except stocks instead of scores

    Time: O(k log n)
    Space: O(n)
*/

#include <stdio.h>

#include <iostream>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Stocks {
public:
    Stocks() {
        
    }
    
    void addStocksVolume(const string& stockSymbol, int volume) {
        if (stockToVolume.find(stockSymbol) != stockToVolume.end()) {
            volumeToStocks[stockToVolume[stockSymbol]].erase(stockSymbol);
        }
        stockToVolume[stockSymbol] += volume;
        volumeToStocks[stockToVolume[stockSymbol]].insert(stockSymbol);
    }
    
    vector<string> topKstocks(int k) {
        vector<string> result;
        
        for (auto it = volumeToStocks.end(); k > 0; it--) {
            unordered_set<string> stocks = it->second;
            for (auto it2 = stocks.begin(); it2 != stocks.end(); it2++) {
                result.push_back(*it2);
                k--;
                if (k == 0) {
                    return result;
                }
            }
            
            if (it == volumeToStocks.begin()) {
                break;
            }
        }
        
        return result;
    }
private:
    // {stock -> volume}
    unordered_map<string, int> stockToVolume;
    // {volume -> {all stocks at this volume}}
    map<int, unordered_set<string>> volumeToStocks;
};

int main() {
    Stocks* obj = new Stocks();
    obj->addStocksVolume("INTC", 12);
    obj->addStocksVolume("CSCO", 20);
    obj->addStocksVolume("AA", 10);
    obj->addStocksVolume("INTC", 18);
    obj->addStocksVolume("UAL", 4);
    obj->addStocksVolume("BOE", 2);
    obj->addStocksVolume("BOA", 16);
    obj->addStocksVolume("BOA", 24);

    vector<string> result = obj->topKstocks(5);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
