/*
Patterns

Refer to Figure 0 for general solution structure

1. Hash Map/Hash Set
2. 2 Pointers
3. Sliding Window
4. Stack, Monotonic Stack
5. Binary Search
6. Linked List
7. Trees
8. Tries
9. Heap/Priority Queue

1. If given array/string(s), need existence, grouping, validity:

- Hash map/hash set
- If numbers/strings, unordered_map/unordered_set
- If lowercase English letters, vector<int> count(26)
- Loop through array and do something
- Ex. check for existence, track counts, check substrings
- Special algos, check for prefix/postfix sums

2. If given sorted array/string, need max/min of something, validity:

- 2 pointers
- Usually starting from the ends and going outside in
- Iterate i or j depending on some condition
- Used to find max/min of something, check existence/validity

3. If given array/string, need longest substring, subarray, repeating:

- Sliding window
- Expand right side pointer (j) as long as it's still valid
- Contract left side pointer (i) until it's no longer invalid
- In general, maintain a valid window and store max/min of something

4. If given array where order in which elements are placed matters:

- (a) Stack, or commonly a (b) monotonic increasing/decreasing stack
- Ex. (a) Reverse Polish Notation, Valid Parentheses
- Ex. (b) Daily Temperatures, Min Stack
- Main idea is to get relative increases/decreases between elements

5. If given a sorted array of numbers, need to find a target/min/max:

- Binary search
- 2 types: (a) finding a target, or (b) finding a minimum/maximum
- For (a), need low <= high to exhaust search on entire array
- For (b), need low < high and low/high lands on the final value

6. If given a linked list:

- Linked list, 1/2/2+ pointers
- Consider dummy node and return dummy->next, if need to return head
- Consider slow/fast pointers, if need to detect cycles or mid of list
- Consider checking curr != NULL vs curr->next != NULL, prev to replace

7. If given a tree:

- DFS/BFS, use DFS if want depth, BFS if want breadth, dep on question
- 3 types of traversals: preorder (V,L,R), inorder (L,V,R), postorder
- DFS: typically inorder, sometimes preorder, refer to Figure 7a
- BFS: level order traversal, iterative, uses a queue, refer Figure 7b

8. If need to add/search strings/words:

- Trie
- Better than hash map if need prefix of words
- Ex. Word Search, Design structure to handle wildcards
- Refer to Figure 8 for Trie implementation

9. If need to maintain order, or need kth largest/smallest:

- Priority queue, min heap or max heap
- Min heap: priority_queue<int, vector<int>, greater<int>> pq;
- Max heap: priority_queue<int> pq;
- kth largest: min heap top because k values larger will be below
- kth smallest: max heap top because k values smaller will be below

*/

// 0. General Solution Structure
class Solution {
public:
    T mySolution(T mySolutionParam) {

    }
private:
    T myHelperVar;
    T myHelper(T myHelperParam) {

    }
};

// 7a. DFS Traversal Structure
void dfs(TreeNode* root, /* more params */) {
    // base case
    if (root == NULL) {
        // do something when base case
        return;
    }
    // recursive case
    // do something when recursive case
    dfs(root->left);
    dfs(root->right);
}

// 7b. BFS Traversal Structure
void bfs(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int count = q.size();
        for (int i = 0; i < count; i++) {
            TreeNode* node = q.front();
            q.pop();
            // do something, dependent on question
            if (node->left != NULL) {
                q.push(node->left);
            }
            if (node->right != NULL) {
                q.push(node->right);
            }
        }
    }
}

// 8. Trie Implementation
class TrieNode {
public:
    TrieNode* children[26];
    bool isWord;
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isWord = false;
    }
};
class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    void insert(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.size(); i++) {
            int curr = word[i] - 'a';
            if (node->children[curr] == NULL) {
                node->children[curr] = new TrieNode();
            }
            node = node->children[curr];
        }
        node->isWord = true;
    }
    bool search(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.size(); i++) {
            int curr = word[i] - 'a';
            if (node->children[curr] == NULL) {
                return false;
            }
            node = node->children[curr];
        }
        return node->isWord;
    }
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (int i = 0; i < prefix.size(); i++) {
            int curr = prefix[i] - 'a';
            if (node->children[curr] == NULL) {
                return false;
            }
            node = node->children[curr];
        }
        return true;
    }
private:
    TrieNode* root;
};
