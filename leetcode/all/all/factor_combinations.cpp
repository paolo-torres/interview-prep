// Given int, return all possible combos of its factors
// Ex. n = 12 -> [[2,6],[3,4],[2,2,3]], n = 37 -> []

// If a factor push back and try + recurse, then backtrack to try more combos

// Time: O(sqrt(n) log n) -> only going from 2 to square of the number, dividing
// Space: O(log n) -> call stack = height of recursive tree = log n

class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<int> curr;
        vector<vector<int>> result;
        helper(n, 2, curr, result);
        return result;
    }
private:
    void helper(int n, int start, vector<int>& curr, vector<vector<int>>& result) {
        if (n < 2) {
            if (curr.size() > 1) {
                result.push_back(curr);
            }
            return;
        }
        
        for (int i = start; i <= n; i++) {
            // if a factor
            if (n % i == 0) {
                curr.push_back(i);
                helper(n / i, i, curr, result);
                curr.pop_back();
            }
        }
    }
};
