// Hash: diff b/w consecutive chars, "+26" for C++, "%26" for circular

// Time: O(n * l)
// Space: O(n * l)

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> m;
        for (int i = 0; i < strings.size(); i++) {
            string key = getKey(strings[i]);
            m[key].push_back(strings[i]);
        }
        
        vector<vector<string>> result;
        for (auto it = m.begin(); it != m.end(); it++) {
            result.push_back(it->second);
        }
        return result;
    }
private:
    string getKey(string& s) {
        string key = "";
        for (int i = 1; i < s.size(); i++) {
            key += (s[i] - s[i - 1] + 26) % 26 + 'a';
        }
        return key;
    }
};
