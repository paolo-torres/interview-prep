/*
    Assume you have a car park (parking lot), with n spaces arranged
    linearly (let's say 10 spaces initially).
    The spaces are all the same size and will fit all vehicles that
    come.
    This car park has 1 attendant, whose job it is to take the key
    from arriving drivers, and park the car. They'll want to park in
    the first available slot from the start to avoid walking too much.
    Later, when a driver wants to collect their car, the attendant
    needs to look up the car's location (unique ID) and retrieve the
    car for the driver. This will leave an empty slot.
    Ex. A B _ D E _ G _ _ _ _
    After a while, car park will become fragmented. So, they want to
    consider a "defrag" operation which will close up the empty slots:
    Ex. A B D E G _ _ _ _ _ _

    Hash map {ID -> idx}, vector of slots, Move Zeroes for defrag()

    Time: O(n)
    Space: O(n)
*/

#include <stdio.h>

#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class ParkingSystem {
public:
    ParkingSystem(int N) {
        n = N;
        slots.resize(n, '_');
        print();
    }

    bool park(char customer) {
        int index = 0;
        while (index < n && slots[index] != '_') {
            index++;
        }
        if (index >= n) {
            return false;
        }

        slots[index] = customer;
        m[customer] = index;

        print();
        return true;
    }

    bool unpark(char customer) {
        if (m.find(customer) == m.end()) {
            return false;
        }

        int index = m[customer];
        slots[index] = '_';
        m.erase(customer);

        print();
        return true;
    }

    void defrag() {
        int start = 0;
        for (int i = 0; i < slots.size(); i++) {
            if (slots[i] != '_') {
                slots[start] = slots[i];
                start++;
            }
        }
        for (int i = start; i < slots.size(); i++) {
            slots[i] = '_';
        }

        print();
    }
private:
    // {customer ID -> index of parking spot}
    unordered_map<char, int> m;
    vector<char> slots;
    int n;

    void print() {
        for (int i = 0; i < slots.size(); i++) {
            cout << slots[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int n = 10;
    ParkingSystem* obj = new ParkingSystem(n);
    obj->park('A');
    obj->park('B');
    obj->park('C');
    obj->park('D');
    obj->park('E');
    obj->unpark('D');
    obj->unpark('B');
    obj->defrag();

    return 0;
}
