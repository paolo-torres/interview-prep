// https://leetcode.com/problems/palindrome-pairs/discuss/79195/O(n-*-k2)-java-solution-with-Trie-structure
// https://leetcode.com/problems/palindrome-pairs/discuss/1660351/some-edge-test-cases-may-trigger-TLE-for-official-solutions

// Time: O(n x l^2), n = number of words, l = length of each word
// Space: O(n x l^2)

class TrieNode {
public:
    TrieNode* children[26];
    int index;
    vector<int> matches;
    
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        index = -1;
    }
};

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        
        for (int i = 0; i < n; i++) {
            insert(words[i], i);
        }
        
        vector<vector<int>> result;
        
        for (int i = 0; i < n; i++) {
            search(words[i], i, result);
        }
        
        return result;
    }
private:
    TrieNode* root = new TrieNode();
    
    void insert(string word, int i) {
        TrieNode* node = root;
        int curr = 0;
        
        for (int j = word.size() - 1; j >= 0; j--) {
            if (isPalindrome(word, 0, j)) {
                node->matches.push_back(i);
            }
            
            curr = word[j] - 'a';
            if (node->children[curr] == NULL) {
                node->children[curr] = new TrieNode();
            }
            node = node->children[curr];
        }
        
        node->index = i;
        node->matches.push_back(i);
    }
    
    void search(string word, int i, vector<vector<int>>& result) {
        TrieNode* node = root;
        int curr = 0;
        int n = word.size();
        
        for (int j = 0; j < n; j++) {
            if (node->index >= 0 && node->index != i) {
                if (isPalindrome(word, j, n - 1)) {
                    result.push_back({i, node->index});
                }
            }
            
            curr = word[j] - 'a';
            if (node->children[curr] == NULL) {
                return;
            }
            node = node->children[curr];
        }
        
        if (node != NULL) {
            for (int j = 0; j < node->matches.size(); j++) {
                if (i == node->matches[j]) {
                    continue;
                }
                result.push_back({i, node->matches[j]});
            }
        }
    }
    
    bool isPalindrome(string word, int i, int j) {
        while (i < j) {
            if (word[i] != word[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
