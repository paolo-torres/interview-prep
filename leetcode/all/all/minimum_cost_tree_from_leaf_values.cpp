// Goal is to find optimal way to convert array into tree
// Don't know best way to divide into left & right subtrees
// DFS/DP: Try all possible ways & recursively apply
// Greedy: Find idx i to minimize arr[i] * arr[i + 1], discard lower
// Optimal: Remove all local mins while finding 1st greater element on left & right
// Given arr A, choose 2 neighbors a & b, remove smaller min(a,b), cost is a * b
// To remove a, needs cost a * b where b >= a, want to minimize this cost, min b

// Time: O(n)
// Space: O(n)

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        stack<int> stk;
        stk.push(INT_MAX);
        
        int result = 0;
        
        for (int i = 0; i < arr.size(); i++) {
            while (!stk.empty() && stk.top() <= arr[i]) {
                int mid = stk.top();
                stk.pop();
                if (!stk.empty()) {
                    result += mid * min(stk.top(), arr[i]);
                }
            }
            stk.push(arr[i]);
        }
        
        while (stk.size() > 2) {
            int left = stk.top();
            stk.pop();
            int right = stk.top();
            result += left * right;
        }
        
        return result;
    }
};
