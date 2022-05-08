/*
    Implement a key value store with transactions.
    Key value store: Set(), Get(), Delete()
    Transactions: Begin(), Commit(), Rollback()
    
    Maintain global & local hash maps
*/

#include <iostream>
#include <list>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Transaction {
public:
    unordered_map<string, string> store;
    Transaction* next;
    Transaction() {
        next = nullptr;
    }
    ~Transaction() {};
};

class TransactionStack {
public:
    Transaction *top;
    int size;
    TransactionStack() {
        top = nullptr;
        size = 0;
    }
    ~TransactionStack() {};
};

class KeyValueStoreWithTransaction {
public:
    // Start new transaction
    // O(1)
    void Begin() {
        Transaction *temp = new Transaction();
        temp->next = ts.top;
        ts.top = temp;
        ts.size++;
    }
    void End() {
        if (ts.top) {
            Transaction *node = ts.top;  
            ts.top = node->next;
            node->next = nullptr;
            ts.size--;
            delete node;
        }
    }

    Transaction *Peek() {
        return ts.top;
    }

    // Merge current transaction with previous
    // O(n) -> n = number of keys
    void Commit() {
        Transaction* active = Peek();
        if (active) {
            for(auto &it : active->store) {
                auto key = it.first, value = it.second;
                globalStore[key] = value;
                if (active->next) {
                    active->next->store[key] = value;
                }
            }
        }
    }

    // Remove last transaction
    // O(1)
    void Rollback() {
        if (ts.top) {
            ts.top->store.clear();
        }
    }

    // Get most recent value of key if it exists
    // O(1)
    void Get(string key) {
        Transaction* active = Peek();
        if (!active) {
            if (globalStore.count(key)) {
                cout << globalStore[key] << "\n";
            } else {
                cout << "not set\n";
            }
        } else {
            if (active->store.count(key)) {
                cout << active->store[key] << "\n";
            } else {
                cout << "not set\n";
            }
        }
    }

    // Set value of specified key for either global or local
    // O(1)
    void Set(string key, string value) {
        Transaction* active = Peek();
        if (!active) {
            globalStore[key] = value;
        } else {
            active->store[key] = value;
        }
    }

    // Removes key value pair if it exists
    // O(1)
    void Delete(string key) {
        Transaction* active = Peek();
        if (!active) {
            if (globalStore.count(key)) {
                globalStore.erase(key);
            }
        } else {
            if (active->store.count(key)) {
                active->store.erase(key);
            }
        }
    }
private:
    TransactionStack ts;
    unordered_map<string, string> globalStore;
};


int main() {
    KeyValueStoreWithTransaction kv;
    kv.Begin();
    kv.Set("v1", "a");
    kv.Set("v2", "b");
    kv.Set("v3", "c");
    {
        kv.Begin();
        kv.Set("v1", "A");
        kv.Set("v2", "B");
        kv.Set("v3", "C");
        kv.Get("v1");
        kv.Get("v2");
        kv.Get("v3");
        kv.Commit();
        kv.End();
    }
    kv.Set("v1", "x");
    kv.Set("v2", "y");
    kv.Set("v3", "z");
    
    kv.Set("v4", "d");
    kv.Set("v5", "e");
    kv.Set("v6", "f");
    kv.Get("v1");
    kv.Get("v2");
    kv.Get("v3");
    kv.Commit();
    kv.End();
    kv.Get("v1");
    kv.Get("v2");
    kv.Get("v3");

    return 0;
}
