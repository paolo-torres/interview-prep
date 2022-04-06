// Time: O(n)
// Space: O(n)

class TrieNode {
public:
    TrieNode* children[26];
    bool isWord;
    
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isWord = false;
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            insert(words[i]);
        }
        
        int maxSize = 0;
        string maxWord = "";
        
        for (int i = 0; i < words.size(); i++) {
            search(words[i], maxSize, maxWord);
        }
        
        return maxWord;
    }
private:
    TrieNode* root = new TrieNode();
    
    void insert(string word) {
        TrieNode* node = root;
        int curr = 0;
        
        for (int i = 0; i < word.size(); i++) {
            curr = word[i] - 'a';
            if (node->children[curr] == NULL) {
                node->children[curr] = new TrieNode();
            }
            node = node->children[curr];
        }
        
        node->isWord = true;
    }
    
    void search(string word, int& maxSize, string& maxWord) {
        TrieNode* node = root;
        int curr = 0;
        
        for (int i = 0; i < word.size(); i++) {
            curr = word[i] - 'a';
            node = node->children[curr];
            if (!node->isWord) {
                return;
            }
        }
        
        if (maxSize < word.size()) {
            maxSize = word.size();
            maxWord = word;
        } else if (maxSize == word.size()) {
            if (word < maxWord) {
                maxWord = word;
            }
        }
    }
};
