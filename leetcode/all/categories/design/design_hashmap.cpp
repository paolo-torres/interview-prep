/*
    Design a HashMap without using any built-in hash table libraries

    Array, hash func (multiplicative, prime), linked list for collisions

    Time: O(1)
    Space: O(n)
*/

struct Node {
    int key;
    int value;
    Node* next;
    
    Node(int k, int v, Node* n) {
        key = k;
        value = v;
        next = n;
    }
};

class MyHashMap {
public:
    // at least greater than # of possible calls
    const static int size = 19997;
    // any random large multiplier, pref prime
    const static int mult = 12582917;
    Node* data[size] = {};
    
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        remove(key);
        int h = hash(key);
        Node* node = new Node(key, value, data[h]);
        data[h] = node;
    }
    
    int get(int key) {
        int h = hash(key);
        Node* node = data[h];
        while (node != NULL) {
            if (node->key == key) {
                return node->value;
            }
            node = node->next;
        }
        return -1;
    }
    
    void remove(int key) {
        int h = hash(key);
        Node* node = data[h];
        if (node == NULL) {
            return;
        }
        if (node->key == key) {
            data[h] = node->next;
            delete node;
            return;
        }
        while (node->next != NULL) {
            if (node->next->key == key) {
                Node* temp = node->next;
                node->next = temp->next;
                delete temp;
                return;
            }
            node = node->next;
        }
    }
private:
    int hash(int key) {
        return (int)((long)key * mult % size);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
