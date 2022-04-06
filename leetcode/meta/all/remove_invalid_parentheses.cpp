// Try all possible states by removing '(' or ')' + check valid
// If valid add to result, else add to queue & carry on to next level
// BFS good bc guarantees # of parentheses removed is minimal

// Time: O(n x 2^n) -> O(n) isValid x O(2^n) pick/don't pick
// Space: O(n x 2^n)

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        queue<string> q;
        unordered_set<string> visited;
        
        q.push(s);
        visited.insert(s);
        
        bool found = false;
        vector<string> result;
        
        while (!q.empty()) {
            string curr = q.front();
            q.pop();
            
            if (isValid(curr)) {
                result.push_back(curr);
                found = true;
            }
            
            if (found) {
                continue;
            }
            
            for (int i = 0; i < curr.size(); i++) {
                if (curr[i] != '(' && curr[i] != ')') {
                    continue;
                }
                string next = curr.substr(0, i) + curr.substr(i + 1);
                if (visited.find(next) == visited.end()) {
                    q.push(next);
                    visited.insert(next);
                }
            }
        }
        
        return result;
    }
private:
    bool isValid(string& str) {
        int balance = 0;
        
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '(') {
                balance++;
            }
            if (str[i] == ')') {
                if (balance == 0) {
                    return false;
                }
                balance--;
            }
        }
        
        if (balance == 0) {
            return true;
        }
        return false;
    }
};
