/*
	Sort tree by its children and return root.

			World
		  /   |   \
		 /    |    \
		C     A     B
	  / |     |    /|\
	 /  |     |   / | \
	E   D     F  H  G  I

	to

		World
	  /   |   \
	 /    |    \
	A     B     C
	|    /|\    |\
	|   / | \   | \
	F  G  H  I  D  E

	BFS, at each level, sort & push children in sorted order

	Time: O(n x m log m) -> n = # of nodes, m = avg # of children
	Space: O(n)
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
	vector<Node*> children;
	Node() {
		val = 0;
	}
};

class Solution {
public:
    Node* sortNodes(Node* root) {
        deque<pair<Node*, Node*>> dq;
		dq.push_back({root, NULL});

		while (!dq.empty()) {
			sort(dq.begin(), dq.end());

			for (int i = 0; i < dq.size(); i++) {
				Node* node = dq.front().first;
				Node* parent = dq.front().second;
				dq.pop_front();

				if (parent != NULL) {
					parent->children.push_back(node);
				}

				for (int i = 0; i < node->children.size(); i++) {
					Node* child = node->children[i];
					dq.push_back({child, node});
				}
				node->children.clear();
			}
		}

		return root;
    }
};

int main() {
    Solution* obj = new Solution();

    return 0;
}
