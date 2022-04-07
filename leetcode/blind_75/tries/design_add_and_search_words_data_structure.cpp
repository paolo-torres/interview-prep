// Time: O(1) addWord, O(num words of size n x n) search
// Space: O(num words) addWord, O(1) search

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        m[word.size()].push_back(word);
    }
    
    bool search(string word) {
        auto it = m.find(word.size());
        if (it != m.end()) {
            vector<string> words = it->second;
            for (int i = 0; i < words.size(); i++) {
                if (isEqual(words[i], word)) {
                    return true;
                }
            }
        }
        return false;
    }
private:
    unordered_map<int, vector<string>> m;
    
    bool isEqual(string curr, string word) {
        for (int i = 0; i < curr.size(); i++) {
            if (word[i] == '.') {
                continue;
            }
            if (word[i] != curr[i]) {
                return false;
            }
        }
        return true;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
