// Time: O(n x l^3), n = number of words, l = length of each word
// Space: O(n)

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(), words.end(), [](const auto& a, const auto& b) {
            return a.size() < b.size();
        });
        
        unordered_set<string> wordDict;
        vector<string> result;
        
        for (int i = 0; i < words.size(); i++) {
            if (wordBreak(words[i], wordDict)) {
                result.push_back(words[i]);
            }
            wordDict.insert(words[i]);
        }
        
        return result;
    }
private:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if (s.empty()) {
            return false;
        }
        
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        
        for (int i = 1; i <= n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (dp[j]) {
                    string word = s.substr(j, i - j);
                    if (wordDict.find(word) != wordDict.end()) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        
        return dp[n];
    }
};
