/*
    Given an array of lowercase English letter words:
    wordA is a predecessor of wordB iff can insert 1 letter anywhere
    in wordA w/o changing order of the other characters to equal wordB
    Word chain is a seq of words w/ predecessor chains (1 -> 2 -> 3 -> ...)
    Return length of longest possible word chain from given array of words
    Ex. words = ["a","b","ba","bca","bda","bdca"] -> 4, ["a","ba","bda","bdca"]

    DFS + memo, generate all possible strings 1 char at a time, words hash set

    Time: O(n x l^2) -> n = number of words in list, l = max length of a word
    Space: O(n)
*/

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            s.insert(words[i]);
        }
        
        int result = 0;
        for (int i = 0; i < words.size(); i++) {
            result = max(result, dfs(words[i]));
        }
        return result;
    }
private:
    unordered_map<string, int> dp;
    unordered_set<string> s;
    
    int dfs(string& currWord) {
        // if we've seen this word already return cached value
        if (dp.find(currWord) != dp.end()) {
            return dp[currWord];
        }
        
        // stores max length of word sequence w/ currWord
        int maxLength = 1;
        
        // generate all possible strings removing 1 char at a time
        for (int i = 0; i < currWord.size(); i++) {
            string newWord = currWord.substr(0, i) + currWord.substr(i + 1);
            // if new word formed is in our set of words, perform dfs
            if (s.find(newWord) != s.end()) {
                int currLength = 1 + dfs(newWord);
                maxLength = max(maxLength, currLength);
            }
        }
        
        dp[currWord] = maxLength;
        return dp[currWord];
    }
};
