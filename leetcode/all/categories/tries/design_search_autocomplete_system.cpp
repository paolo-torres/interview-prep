/*
    Given sentences & times, return top 3 historical hot sentences w/ same prefix
    Users may input a sentence (at least 1 word & end with a special char '#')

    Implement trie, add hash map {sentence -> count} to track top 3 results

    Time: O(n log n)
    Space: O(n)
*/

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    unordered_map<string, int> counter;
    TrieNode() {};
};

class AutocompleteSystem {
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        root = new TrieNode();
        for (int i = 0; i < sentences.size(); i++) {
            insert(sentences[i], times[i]);
        }
        prefix = "";
    }
    
    vector<string> input(char c) {
        if (c == '#') {
            insert(prefix, 1);
            prefix.clear();
            return {};
        }
        prefix += c;
        
        TrieNode* node = root;
        for (int i = 0; i < prefix.size(); i++) {
            int curr = prefix[i];
            if (!node->children[curr]) {
                return {};
            }
            node = node->children[curr];
        }
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, compare> pq;
        unordered_map<string, int> count = node->counter;
        for (auto it = count.begin(); it != count.end(); it++) {
            pq.push({it->second, it->first});
        }
        
        vector<string> result;
        for (int i = 0; i < 3; i++) {
            if (pq.empty()) {
                break;
            }
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
private:
    TrieNode* root;
    string prefix;
    
    struct compare {
        bool operator()(pair<int, string>& a, pair<int, string>& b) {
            return a.first < b.first || (a.first == b.first && a.second.compare(b.second) > 0);
        }
    };
    
    void insert(string sentence, int time) {
        TrieNode* node = root;
        for (int i = 0; i < sentence.size(); i++) {
            int letter = sentence[i];
            if (!node->children[letter]) {
                node->children[letter] = new TrieNode();
            }
            node = node->children[letter];
            node->counter[sentence] += time;
        }
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */
