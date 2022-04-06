// https://leetcode.com/problems/prefix-and-suffix-search/discuss/144432/Java-Beat-95-just-small-modifications-in-implementing-Trie.

// Time: O(n x l^2 + ql), n = number of words, l = max length of a word, q = number of queries
// Space: O(n x l^2)

class TrieNode {
public:
    TrieNode* children[27];
    int index;
    
    TrieNode() {
        for (int i = 0; i < 27; i++) {
            children[i] = NULL;
        }
        index = 0;
    }
};

class WordFilter {
public:
    WordFilter(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            string word = '{' + words[i];
            insert(word, i);
            for (int j = 0; j < word.size(); j++) {
                insert(word.substr(j + 1) + word, i);
            }
        }
    }
    
    int f(string prefix, string suffix) {
        TrieNode* node = root;
        
        vector<char> word;
        for (int i = 0; i < suffix.size(); i++) {
            word.push_back(suffix[i]);
        }
        word.push_back('{');
        for (int i = 0; i < prefix.size(); i++) {
            word.push_back(prefix[i]);
        }
        
        int curr = 0;
        for (int i = 0; i < word.size(); i++) {
            curr = word[i] - 'a';
            if (node->children[curr] == NULL) {
                return -1;
            }
            node = node->children[curr];
        }
        
        return node->index;
    }
private:
    TrieNode* root = new TrieNode();
    
    void insert(string word, int index) {
        TrieNode* node = root;
        int curr = 0;
        
        for (int i = 0; i < word.size(); i++) {
            curr = word[i] - 'a';
            if (node->children[curr] == NULL) {
                node->children[curr] = new TrieNode();
            }
            node = node->children[curr];
            node->index = index;
        }
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
