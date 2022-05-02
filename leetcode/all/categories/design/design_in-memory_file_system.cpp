/*
    Design a data structure that simulates an in-memory file system

    Trie to store paths & directories (but really just a node class)

    Time: O(n)
    Space: O(n)
*/

class TrieNode {
public:
    unordered_map<string, TrieNode*> children;
    bool isFile;
    string content;
    TrieNode() : isFile(false) {}
};

class FileSystem {
public:
    FileSystem() {
        root = new TrieNode();
    }
    
    vector<string> ls(string path) {
        vector<string> strs = getStrs(path);
        TrieNode* node = root;
        for (int i = 0; i < strs.size(); i++) {
            node = node->children[strs[i]];
        }
        
        if (node->isFile) {
            return {strs.back()};
        }
        
        vector<string> result;
        for (auto it = node->children.begin(); it != node->children.end(); it++) {
            result.push_back(it->first);
        }
        sort(result.begin(), result.end());
        return result;
    }
    
    void mkdir(string path) {
        vector<string> strs = getStrs(path);
        TrieNode* node = root;
        
        for (int i = 0; i < strs.size(); i++) {
            if (!node->children.count(strs[i])) {
                node->children[strs[i]] = new TrieNode();
            }
            node = node->children[strs[i]];
        }
    }
    
    void addContentToFile(string filePath, string content) {
        vector<string> strs = getStrs(filePath);
        TrieNode* node = root;
        
        for (int i = 0; i < strs.size(); i++) {
            if (!node->children.count(strs[i])) {
                node->children[strs[i]] = new TrieNode();
            }
            node = node->children[strs[i]];
        }
        
        node->isFile = true;
        node->content += content;
    }
    
    string readContentFromFile(string filePath) {
        vector<string> strs = getStrs(filePath);
        TrieNode* node = root;
        
        for (int i = 0; i < strs.size(); i++) {
            node = node->children[strs[i]];
        }
        
        return node->content;
    }
private:
    TrieNode* root;
    
    vector<string> getStrs(string& path) {
        int i = 1;
        int j = 1;
        
        vector<string> result;
        
        while (j <= path.size()) {
            if (i != j && (j == path.size() || path[j] == '/')) {
                result.push_back(path.substr(i, j - i));
                i = j + 1;
            }
            j++;
        }
        
        return result;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */
