// DFS + memoization, iterate thru all prefix/suffix combos, store results

// Time: O(2^n)
// Space: O(2^n)

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words;
        for (int i = 0; i < wordDict.size(); i++) {
            words.insert(wordDict[i]);
        }
        unordered_map<string, vector<string>> cache;
        
        return dfs(s, words, cache);
    }
private:
    vector<string> dfs(string s, unordered_set<string>& words, unordered_map<string, vector<string>>& cache) {
        vector<string> result;
        
        if (s.empty()) {
            return result;
        }
        if (cache.find(s) != cache.end()) {
            return cache[s];
        }
        
        if (words.find(s) != words.end()) {
            result.push_back(s);
        }
        
        for (int i = 1; i < s.size(); i++) {
            string t = s.substr(i);
            if (words.find(t) != words.end()) {
                vector<string> curr = dfs(s.substr(0, i), words, cache);
                for (int j = 0; j < curr.size(); j++) {
                    result.push_back(curr[j] + " " + t);
                }
            }
        }
        
        cache[s] = result;
        return result;
    }
};
