// Backtracking, try all options, evaluate on the fly, track curr & prev
// Need prev to calculate multiply: next = curr - prev + prev * value

// Time: O(4^n) -> +, -, *, and just move up one (no operator)
// Space: O(n)

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        dfs(num, target, "", 0, 0, 0, result);
        return result;
    }
private:
    void dfs(string num, int target, string s, int pos, long curr, long prev, vector<string>& result) {
        if (pos == num.size()) {
            if (curr == target) {
                result.push_back(s);
            }
            return;
        }
        
        string t = "";
        long value = 0;
        
        for (int i = pos; i < num.size(); i++) {
            if (i > pos && num[pos] == '0') {
                break;
            }
            
            t += num[i];
            value = value * 10 + num[i] - '0';
            
            if (pos == 0) {
                dfs(num, target, s + t, i + 1, value, value, result);
            } else {
                dfs(num, target, s + '+' + t, i + 1, curr + value, value, result);
                dfs(num, target, s + '-' + t, i + 1, curr - value, -value, result);
                dfs(num, target, s + '*' + t, i + 1, curr - prev + prev * value, prev * value, result);
            }
        }
    }
};
