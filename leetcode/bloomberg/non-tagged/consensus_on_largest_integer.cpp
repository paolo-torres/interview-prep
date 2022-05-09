/*
    Imagine we have a network of nodes where new info can be passed
    from 1 node to another analogous to how new gossip spreads from
    1 person to the next. In order for info to spread across the
    network, each node finds a node to pass down the latest info or
    gossip it knows and this process repeats until the info is
    consistent across all nodes.
    Let's say we have a list of nodes each holding a unique positive
    integer and we'd like to use this method to reach a consensus on
    what the largest integer is.

    Assumptions:
    1) Given random neighbor assignments, 3 neighbors per node
    2) Given the assumption that this graph is fully connected
    3) No messages are lost
    
    Explore to find global max, then propagate to all nodes

    Time: O(V + E)
    Space: O(V)
*/

#include <stdio.h>

#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Node {
public:
    int val;
    int largest;
    vector<Node*> children;

    Node(int value) {
        val = value;
        // initially, largest value it knows is itself
        largest = value;
    };
};

class Solution {
public:
    int consensus(Node* root) {
        int result = INT_MIN;
        explore(root, result);
        propagate(root, result);
        return result;
    }
private:
    void explore(Node* node, int& result) {
        if (node == NULL) {
            return;
        }
        result = max(result, node->val);
        for (int i = 0; i < node->children.size(); i++) {
            Node* child = node->children[i];
            explore(child, result);
        }
    }

    void propagate(Node* node, int val) {
        if (node == NULL) {
            return;
        }
        node->largest = val;
        for (int i = 0; i < node->children.size(); i++) {
            Node* child = node->children[i];
            propagate(child, val);
        }
    }
};

int main() {
    Solution* obj = new Solution();

    return 0;
}
