/*
Patterns

Refer to Figure 0 for general solution structure
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

/*
1. If given array/string(s), need existence, grouping, validity:
2. If given sorted array/string, need max/min of something, validity:
3. If given array/string, need longest substring, subarray, repeating:
4. If given array where order in which elements are placed matters:
5. If given a sorted array of numbers, need to find a target/min/max:
6. If given a linked list:
7. If given a tree:
8. If need to add/search strings/words:
9. If need to maintain order, or need kth largest/smallest:
10. If need to generate all possible combos/permutations:
11. If given either (1) a matrix, or (2) a graph of nodes and edges:
12. If given either (1) a matrix, or (2) a graph of nodes and edges:
13. If need maximum/minimum/# of ways of an array of nums or string:
14. If need maximum/minimum/# of ways of an array of nums or string:

1. Hash Map/Hash Set
2. 2 Pointers
3. Sliding Window
4. Stack, Monotonic Stack
5. Binary Search
6. Linked List
7. Trees
8. Tries
9. Heap/Priority Queue
10. Backtracking
11. Graphs
12. Advanced Graphs
13. 1-D Dynamic Programming
14. 2-D Dynamic Programming

1. If given array/string(s), need existence, grouping, validity:

- Hash map/hash set
- If numbers/strings, unordered_map/unordered_set
- If lowercase English letters, vector<int> count(26)
- Loop through array and do something
- Ex. check for existence, track counts, check substrings
- Special algos, check for prefix/postfix sums
- Ex. Group Anagrams, Longest Consecutive Sequence, Valid Sudoku

2. If given sorted array/string, need max/min of something, validity:

- 2 pointers
- Usually starting from the ends and going outside in
- Iterate i or j depending on some condition
- Used to find max/min of something, check existence/validity
- Ex. 3Sum, Trapping Rain Water, Valid Palindrome

3. If given array/string, need longest substring, subarray, repeating:

- Sliding window
- Expand right side pointer (j) as long as it's still valid
- Contract left side pointer (i) until it's no longer invalid
- In general, maintain a valid window and store max/min of something
- Ex. Longest Substring w/o Repeating Chars, Minimum Window Substring

4. If given array where order in which elements are placed matters:

- (a) Stack, or commonly a (b) monotonic increasing/decreasing stack
- Ex. (a) Reverse Polish Notation, Valid Parentheses
- Ex. (b) Daily Temperatures, Min Stack
- Main idea is to get relative increases/decreases between elements
- Ex. Daily Temperatures, Evaluate RPN, Valid Parentheses

5. If given a sorted array of numbers, need to find a target/min/max:

- Binary search
- 2 types: (a) finding a target, or (b) finding a minimum/maximum
- For (a), need low <= high to exhaust search on entire array
- For (b), need low < high and low/high lands on the final value
- Ex. Median of Two Sorted Arrays, Search in Rotated Sorted Array

6. If given a linked list:

- Linked list, 1/2/2+ pointers
- Consider dummy node and return dummy->next, if need to return head
- Consider slow/fast pointers, if need to detect cycles or mid of list
- Consider checking curr != NULL vs curr->next != NULL, prev to replace
- Linked List Cycle, LRU Cache, Merge k Sorted Lists

7. If given a tree:

- DFS/BFS, use DFS if want depth, BFS if want breadth, dep on question
- 3 types of traversals: preorder (V,L,R), inorder (L,V,R), postorder
- DFS: typically inorder, sometimes preorder, refer to Figure 7a
- BFS: level order traversal, iterative, uses a queue, refer Figure 7b
- Ex. Binary Tree Maximum Path Sum, Construct From Preorder and Inorder
*/

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

/*
8. If need to add/search strings/words:

- Trie
- Better than hash map if need prefix of words
- Ex. Word Search, Design structure to handle wildcards
- Refer to Figure 8 for Trie implementation
- Design Add and Search Words Data Structure, Word Search II
*/

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

/*
9. If need to maintain order, or need kth largest/smallest:

- Priority queue, min heap or max heap
- Min heap: priority_queue<int, vector<int>, greater<int>> pq;
- Max heap: priority_queue<int> pq;
- kth largest: min heap top because k values larger will be below
- kth smallest: max heap top because k values smaller will be below
- Find Median From Data Stream, k Closest Points to Origin

10. If need to generate all possible combos/permutations:

- Backtracking, "trying different options and undoing"
- The idea of "2 choices: either take or don't take"
- DFS with base case result and recursive for loop "take, dfs, undo"
- Refer to Figure 10 for an example
- Ex. Combination Sum, N-Queens, Permutations, Subsets
*/

// Figure 10. Backtracking Structure Example
void dfs(vector<int>& candidates, int target, int sum, int start
    vector<int>& curr, vector<vector<int>>& result) {
    // base cases
    if (sum > target) {
        return;
    }
    if (sum == target) {
        result.push_back(curr);
    }
    // recursive case for loop to "try and undo"
    // dep on question but idea is the same
    for (int i = start; i < candidates.size(); i++) {
        curr.push_back(candidates[i]);
        dfs(candidates, target, sum + candidates[i], i, curr, result);
        curr.pop_back();
    }
}

/*
11. If given either (1) a matrix, or (2) a graph of nodes and edges:

- Graphs, (1) and (2) are solved in completely different ways

- (1) Given some kind of grid with certain elements in it
- DFS if just want to simply explore each spot and "do something"
- Instead of a "visited" matrix, just modify the input
- BFS if specifically need shortest paths or "propagate outwards"
- Refer to Figure 11.1.a and Figure 11.1.b
- Ex. Number of Islands, Rotting Oranges, Walls and Gates

- (2) Given a graph structure where "there's an order dependency"
- Hash map/adjacency list to store this "order dependency"
- Directed = 1-way hash map, undirected = 2-way hash map (usually)
- Checking for validity: detect cycles with visited hash set/array
- Solved again with either DFS or BFS
- Refer to Figure 11.2 for 1-way and 2-way mappings
- Ex. Course Schedule, Graph Valid Tree, Clone Graph

- Third special case: given connected components/connections/etc.
- Union Find, refer to Figure 11.3 for Union and Find algos
- Find: determines which subsets an element is in
- Union: joins 2 subsets into a single subset
- Ex. Redundant Connection, Number of Connected Components
*/

// Figure 11.1.a. Graph Type 1 DFS
void dfs(vector<vector<char>>& grid, int i, int j, int m, int n) {
    // almost always check out of bounds like this, + anything else
    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0') {
        return;
    }
    // do the "visit" step
    grid[i][j] = '0';
    // explore and traverse in the 4 directions
    dfs(grid, i - 1, j, m, n);
    dfs(grid, i + 1, j, m, n);
    dfs(grid, i, j - 1, m, n);
    dfs(grid, i, j + 1, m, n);
}

// Figure 11.1.b. Graph Type 1 BFS
void bfs() {
    queue<pair<int, int>> q;
    // fill queue with the cells "to be explored"
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (rooms[i][j] == 0) {
                q.push({i, j});
            }
        }
    }
    while (!q.empty()) {
        // extract the coordinates
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        // search in 4 directions
        for (int i = 0; i < 4; i++) {
            // extract the next set of coordinates
            int x = row + dirs[i][0];
            int y = col + dirs[i][1];
            // discard any that are out of bounds/invalid
            if (x < 0 || x >= m || y < 0 || y >= n
                || rooms[x][y] != INT_MAX) {
                continue;
            }
            // "do something", dependent on question
            rooms[x][y] = rooms[row][col] + 1;
            // push next cell to be searched
            q.push({x, y});
        }
    }
}
// setup the 4 directions "to be searched"
vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

// Figure 11.2. Directed/Undirected Graph Mappings
// directed
unordered_map<int, vector<int>> m;
for (int i = 0; i < prerequisites.size(); i++) {
    m[prerequisites[i][0]].push_back(prerequisites[i][1]);
}
// undirected
vector<vector<int>> adj(n);
for (int i = 0; i < edges.size(); i++) {
    vector<int> edge = edges[i];
    adj[edge[0]].push_back(edge[1]);
    adj[edge[1]].push_back(edge[0]);
}

// Figure 11.3. Union Find
int doFind(vector<int>& parents, int n) {
    int p = parents[n];
    while (p != parents[p]) {
        parents[p] = parents[parents[p]];
        p = parents[p];
    }
    return p;
}
int doUnion(vector<int>& parents, vector<int>& ranks,
    int n1, int n2) {
    int p1 = doFind(parents, n1);
    int p2 = doFind(parents, n2);
    if (p1 == p2) {
        return 0;
    }
    if (ranks[p1] > ranks[p2]) {
        parents[p2] = p1;
        ranks[p1] += ranks[p2];
    } else {
        parents[p1] = p2;
        ranks[p2] += ranks[p1];
    }
    return 1;
}

/*
12. If given either (1) a matrix, or (2) a graph of nodes and edges:

- Advanced graphs, same 2 cases as above

- (1) If need shortest paths, consider Dijkstra's: BFS + min heap
- Refer to Figure 12.1
- Ex. Swim in Rising Water, Cheapest Flights Within k Stops

- (2) More advanced cases of "order dependency", topological sort
- Same idea: hash map order dependency + DFS/BFS
- Ex. Reconstruct Itinerary, Alien Dictionary
*/

// Figure 12.1. Dijkstra's Algorithm
priority_queue<vector<int>, vector<vector<int>>,
    greater<vector<int>>> pq;
// will sort by the first param
pq.push({result, 0, 0});
while (!pq.empty()) {
    // this will be the minimum value for "shortest path"
    vector<int> curr = pq.top();
    pq.pop();
    result = max(result, curr[0]);
    for (int i = 0; i < 4; i++) {
        int x = curr[1] + dirs[i][0];
        int y = curr[2] + dirs[i][1];
        if (x < 0 || x >= n || y < 0 || y >= n || visited[x][y]) {
            continue;
        }
        if (x == n - 1 && y == n - 1) {
            return result;
        }
        pq.push({grid[x][y], x, y});
        visited[x][y] = true;
    }
}

/*
13. If need maximum/minimum/# of ways of an array of nums or string:

- 1-D dynamic programming
- Why DP? When to use DP?
- When (1) Max/min, (2) make decisions based on previous decisions
- "Decision": is it worth it to consider this number?

- Framework to solve DP:
- (1) Need some function or array that represents result (DP array)
- (2) Way to transition between states (recurrence relation)
- (3) Need a base case (initial solution for every subproblem)

- Refer to Figure 13 for DP structure
- Ex. Coin Change, Decode Ways, House Robber, LIS, Word Break
*/

// Figure 13. 1-D DP Structure Example
// initialize DP array
vector<int> dp(n, 1);
// loop through given input
for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
        // if a certain case is true (dep on question)
        if (nums[j] < nums[i]) {
            // update DP according to recurrence relation
            dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    result = max(result, dp[i]);
}

/*
14. If need maximum/minimum/# of ways of an array of nums or string:

- 2-D dynamic programming
- DFS -> DFS + memo -> iterative/bottom-up DP
- For DFS + memo, very often cache on index
- Example caching: map<pair<int, int>, int> dp;
                   {(i, j) -> max/min/# ways}
- Refer to Figure 14.a for typical DFS + memo structure
- Refer to Figure 14.b for typical iterative DP
- Ex. Edit Distance, LCS, Longest Increasing Path in a Matrix
*/

// Figure 14.a. 2-D DFS + Memoization Example
// {(i, j) -> longest increasing path at (i, j)}
map<pair<int, int>, int> dp;
int dfs(vector<vector<int>>& matrix, int prev,
    int i, int j, int m, int n) {
    // all base cases
    if (i < 0 || i >= m || j < 0 || j >= n || matrix[i][j] <= prev) {
        return 0;
    }
    // if already seen return cached value
    if (dp.find({i, j}) != dp.end()) {
        return dp[{i, j}];
    }
    // recursive case, dependent on question
    int result = 1;
    result = max(result,
        1 + dfs(matrix, matrix[i][j], i - 1, j, m, n));
    result = max(result,
        1 + dfs(matrix, matrix[i][j], i + 1, j, m, n));
    result = max(result,
        1 + dfs(matrix, matrix[i][j], i, j - 1, m, n));
    result = max(result,
        1 + dfs(matrix, matrix[i][j], i, j + 1, m, n));
    // store result in cache for future computations
    dp[{i, j}] = result;
    return dp[{i, j}];
}

// Figure 14.b. 2-D Iterative DP Example
vector<vector<int>> dp(m + 1, vector<int>(n + 1));
// base cases
for (int i = 1; i <= m; i++) {
    dp[i][0] = i;
}
for (int j = 1; j <= n; j++) {
    dp[0][j] = j;
}
for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
        // loop through, for each comparison, do something
        if (word1[i - 1] == word2[j - 1]) {
            dp[i][j] = dp[i - 1][j - 1];
        } else {
            dp[i][j] = min(dp[i - 1][j - 1],
                       min(dp[i - 1][j], dp[i][j - 1])) + 1;
        }
    }
}
return dp[m][n];

/*
Common Follow-Up Questions and Answers

Problems where input is a collection or some kind of sequence:

1. What if this were running on multiple machines?
- Need a way to avoid duplicate work or conflicting actions
without necessarily being able to just lock the way you could
in a concurrency problem (since on multiple machines)
- Use consistent hashing to figure out if I should act on this
entity or "use load balancer to route inputs to particular
machines and here's how I would decide which goes where"

2. What if it were multithreaded on one?
- Concurrency, use semaphore or lock to maintain data integrity

3. What if it can't fit in memory?
- Turn to stream processing
- Either 1) maintain some kind of state and have multiple calls
to the method, ideally bounding the amount of space
- Or 2) take in a generator or similar type and see if that can 
le me reduce the space complexity by not storing every entry
from it at once

Problems that involve some kind of preprocessing:

4. What if this were called a bunch of times?
- Extract to have preprocessing
- Make it stateful, preprocess it into a cache, and then access
at request time

Problems that involve comparisons, grouping, analysis:

5. Can we make it faster if we don't care about perfect accuracy?
- Ratios can be estimated with techniques like sampling
- Fast but non-guaranteed comparisons can be done with hashing
- Probabilistic data structures that use hash, like bloom filters,
trade accuracy for speed
*/
