// 2 pointers, comparing s1[i] & s2[j], literal & wildcard matching
// 2000 bc max diff is 3 digits, s1 longer/shorter s2 -> +/- 1000

class Solution {
public:
    bool possiblyEquals(string s1, string s2) {
        return dfs(0, 0, 0, s1, s2);
    }
private:
    bool cache[41][41][2000];
    
    bool dfs(int i, int j, int diff, string s1, string s2) {
        if (i == s1.size() && j == s2.size()) {
            return diff == 0;
        }
        
        if (cache[i][j][diff + 1000] != NULL) {
            return cache[i][j][diff + 1000];
        }
        
        if (i < s1.size() && j < s2.size() && diff == 0 && s1[i] == s2[j]) {
            if (dfs(i + 1, j + 1, 0, s1, s2)) {
                cache[i][j][1000] = true;
                return true;
            }
        }
        
        if (i < s1.size() && !isDigit(s1[i]) && diff > 0) {
            if (dfs(i + 1, j, diff - 1, s1, s2)) {
                cache[i][j][diff + 1000] = true;
                return true;
            }
        }
        
        if (j < s2.size() && !isDigit(s2[j]) && diff < 0) {
            if (dfs(i, j + 1, diff + 1, s1, s2)) {
                cache[i][j][diff + 1000] = true;
                return true;
            }
        }
        
        int val = 0;
        for (int k = i; k < s1.size(); k++) {
            if (!isDigit(s1[k])) {
                break;
            }
            val = val * 10 + (s1[k] - '0');
            if (dfs(k + 1, j, diff - val, s1, s2)) {
                cache[i][j][diff + 1000] = true;
                return true;
            }
        }
        
        val = 0;
        for (int k = j; k < s2.size(); k++) {
            if (!isDigit(s2[k])) {
                break;
            }
            val = val * 10 + (s2[k] - '0');
            if (dfs(i, k + 1, diff + val, s1, s2)) {
                cache[i][j][diff + 1000] = true;
                return true;
            }
        }
        
        cache[i][j][diff + 1000] = false;
        return false;
    }
    
    bool isDigit(char c) {
        return c >= '0' && c <= '9';
    }
};
