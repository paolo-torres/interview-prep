// Return longest list that starts at index "index"
// If "index" not pointing at an element, return empty

// Time: O(n)
// Space: O(n)

class OrderedStream {
public:
    OrderedStream(int n) {
        index = 1;
        for (int i = 0; i < n + 1; i++) {
            s.push_back("");
        }
    }
    
    vector<string> insert(int idKey, string value) {
        s[idKey] = value;
        vector<string> result;
        while (index < s.size() && s[index] != "") {
            result.push_back(s[index]);
            index++;
        }
        return result;
    }
private:
    int index;
    vector<string> s;
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */
