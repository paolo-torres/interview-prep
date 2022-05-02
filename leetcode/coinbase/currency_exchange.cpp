/*
    A list of currency relationships with exchange values (BTC - USD).
    Find the best exchange rate from currency1 to currency2.
    [
        {"source": "USD", "target": "BTC", "bid": 99, "ask": 100},
        {"source": "EUR", "target": "BTC", "bid": 115, "ask": 120},
        {"source": "USD", "target": "ETH", "bid": 98, "ask": 100},
        {"source": "EUR", "target": "ETH", "bid": 400, "ask": 420}
    ]

    Backtracking, try all paths from src to dst & find max product

    Time: O(n!)
    Space: O(n)
*/

#include <stdio.h>

#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class CurrencyExchange {
public:
    CurrencyExchange(string& curr1, string& curr2,
        unordered_map<string, unordered_map<string, int>>& g) {
        source = curr1;
        target = curr2;
        graph = g;
    }

    int getCurrencyExchangeRate() {
        unordered_set<string> seen;
        seen.insert(source);
        return backtrack(source, seen);
    }
private:
    string source;
    string target;
    unordered_map<string, unordered_map<string, int>> graph;

    int backtrack(string& current, unordered_set<string>& seen) {
        if (current == target) {
            return 1;
        }

        int product = 0;
        if (graph.find(current) != graph.end()) {
            unordered_map<string, int> neighbor = graph[current];
            for (auto it = neighbor.begin(); it != neighbor.end(); it++) {
                string currency = it->first;
                int rate = it->second;

                if (seen.find(currency) == seen.end()) {
                    seen.insert(currency);
                    product = max(product, rate * backtrack(currency, seen));
                    seen.erase(currency);
                }
            }
        }
        return product;
    }
};

int main() {
    // vector<vector<string>> exchanges = {
    //     {"A", "B"}, {"A", "D"},
    //     {"B", "A"}, {"B", "D"}, {"B", "E"}, {"B", "C"},
    //     {"D", "A"}, {"D", "B"}, {"D", "E"},
    //     {"E", "B"}, {"E", "D"}, {"E", "C"},
    //     {"C", "B"}, {"C", "E"}
    // };
    // vector<int> rates = {
    //     6, 1,
    //     6, 2, 2, 5,
    //     1, 2, 1,
    //     2, 1, 5,
    //     5, 5
    // };
    // unordered_map<string, unordered_map<string, int>> m;
    // int rateIndex = 0;
    // // if input given both ways (prob not)
    // for (int i = 0; i < exchanges.size(); i++) {
    //     m[exchanges[i][0]][exchanges[i][1]] = rates[rateIndex];
    //     rateIndex++;
    // }
    // // if input given 1 way (prob)
    // for (int i = 0; i < exchanges.size(); i++) {
    //     m[exchanges[i][0]][exchanges[i][1]] = rates[rateIndex];
    //     m[exchanges[i][1]][exchanges[i][0]] = rates[rateIndex];
    //     rateIndex++;
    // }

    unordered_map<string, unordered_map<string, int>> g = {
        {"A", {{"B", 6}, {"D", 1}}},
        {"B", {{"A", 6}, {"D", 2}, {"E", 2}, {"C", 5}}},
        {"D", {{"A", 1}, {"B", 2}, {"E", 1}}},
        {"E", {{"B", 2}, {"D", 1}, {"C", 5}}},
        {"C", {{"B", 5}, {"E", 5}}}
    };
    string curr1 = "A";
    string curr2 = "C";
    CurrencyExchange* obj = new CurrencyExchange(curr1, curr2, g);
    cout << obj->getCurrencyExchangeRate() << endl;

    return 0;
}
