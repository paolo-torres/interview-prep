/*
    Design an algorithm that accepts a stream of chars & checks:
    if a suffix of these chars is a string of a given array of words
    Ex. words = ["abc","xyz"], stream: 'a','x','y','z' -> true, "xyz"

    Trie, but reversed since suffix, then compare w/ stream in reverse

    Time: O(n) -> n = max length of a word
    Space: O(n)
*/

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

class StreamChecker {
public:
    StreamChecker(vector<string>& words) {
        root = new TrieNode();
        s = "";
        
        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            
            TrieNode* node = root;
            int curr = 0;
            
            for (int j = word.size() - 1; j >= 0; j--) {
                curr = word[j] - 'a';
                if (node->children[curr] == NULL) {
                    node->children[curr] = new TrieNode();
                }
                node = node->children[curr];
            }
            
            node->isWord = true;
        }
    }
    
    bool query(char letter) {
        s += letter;
        
        TrieNode* node = root;
        int curr = 0;
        
        for (int i = s.size() - 1; i >= 0; i--) {
            if (node == NULL) {
                return false;
            }
            curr = s[i] - 'a';
            node = node->children[curr];
            if (node != NULL && node->isWord) {
                return true;
            }
        }
        
        return false;
    }
private:
    TrieNode* root;
    string s;
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
