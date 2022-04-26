/*
    Given a string, encode it such that its encoded length is shortest
    k[encoded_string], if encoding doesn't make it shorter, don't do it
    Ex. s = "aaa" -> "aaa" (not shorter), s = "aaaaa" -> "5[a]" (4 vs 5 chars)

    DFS + memo, for each letter encode to k[encoded_string], cache on seen strings

    Time: O(n^3)
    Space: O(n)
*/

class Solution {
public:
    string encode(string s) {
        return dfs(s);
    }
private:
    unordered_map<string, string> m;
    
    string dfs(string s) {
        // encoding will definitely not make it shorter
        if (s.size() < 5) {
            return s;
        }
        // if we've seen this string already
        if (m.find(s) != m.end()) {
            return m[s];
        }
        
        string result = s;
        
        for (int i = 0; i < s.size(); i++) {
            string t = s.substr(0, i + 1);
            int count = getRepetitions(s, t);
            string curr = "";
            for (int k = 1; k <= count; k++) {
                // no repeating substrings
                if (k == 1) {
                    curr = t + dfs(s.substr(i + 1));
                // repeating substrings
                } else {
                    curr = to_string(k) + "[" + dfs(t) + "]" + dfs(s.substr(k * t.size()));
                }
                if (curr.size() < result.size()) {
                    result = curr;
                }
            }
        }
        
        m[s] = result;
        return result;
    }
    
    int getRepetitions(string& s, string& t) {
        int i = 0;
        int count = 0;
        while (i < s.size()) {
            if (s.substr(i, t.size()) != t) {
                break;
            }
            count++;
            i += t.size();
        }
        return count;
    }
};
